#include "app.h"
extern keypad_t keypad_1;

#define index_of_owner 1    // Give a value to the owner to see if he entered
#define index_of_employee 2 // Give a value to the owner to see if he entered
#define index_of_no_one 3   // Give a value to indicate that a foreigner tries to enter
#define password_length 4   // fixed length to the password

/********************************Global Variables*********************************/
uint8_t key_val = 255;       // value of key you press
uint8_t flagin = 0;          /// to check if password correct it's value will be 1 else the passward is wrong
uint8_t check_pass[20];      // password the user enter
uint8_t number_digit = 0;    // to know how many number user enter
uint8_t index_passward = 0;  ////// using as index of check_password array
uint8_t number_of_users = 2; // to know how many user in the system
uint8_t index_of_user = 0;   // to know which user in system that enter the password
uint8_t i = 0;               /// to check if i enter wrong passward more than 3 times or not
uint8_t someone_entered = 0; // flag if someone entered the password correctly
user_t users[2];             /// store array of users to store all data in it

/************ API*************
 *intialize lcd
 *intialze keypad
 *keyvalue
 *intialize my system users
 */
void app_init(void)
{
    /***intialize UART***/
    UART_void_Init_Master(UBRR_Val);
    /**intialize lcd***/
    HLCD_INIT();
    /*intialze keypad*/
    keypad_inti(&keypad_1);
    /*intialize keyvalue*/
    key_val = '\0';
    /*intialize my system users*/
    strcpy(users[0].position, "Owner");
    strcpy(users[0].name, "Ahmed");
    users[0].password[0] = 1;
    users[0].password[1] = 1;
    users[0].password[2] = 1;
    users[0].password[3] = 1;
    strcpy(users[1].position, "employee");
    strcpy(users[1].name, "Omar");
    users[1].password[0] = 1;
    users[1].password[1] = 1;
    users[1].password[2] = 3;
    users[1].password[3] = 4;
}
/************ API*************
 *check if passward the user set it founded in the system or not
 */
/************ API*************
 *check if passward the user set it founded in the system or not
 */
uint8_t Cheack_Password(uint8_t x)
{
    /* if passward less than or more than right length of passward retrun false */
    if ((number_digit < 4) | (number_digit > 4))
        return 0;
    /*intialize variable ret to know hoe many numbers in password same if all password same will return true*/
    uint8_t ret = 0;
    /*will looping to compare with all users in my system */
    for (uint8_t n = 0; n < number_of_users; n++)
    {
        ret = 0;
        /*will looping to check every element of user[n] paswword and the password that entered in the screen */
        for (uint8_t counter = 0; counter < x - 1; counter++)
        {
            /*if element the same increment ret by one */
            if (users[n].password[counter] == check_pass[counter])
            {
                ret++;
            }
        }
        /*if ret == x-1 that refere to all numbers are same so enter to the system */
        if (ret == x - 1)
        {
            /* to know that password own to the user number n */
            index_of_user = n;
            /*to return true */
            return 1;
        }
    }
    /*if not true that mean that password not on the system */
    return 0;
}
/************ API*************
 *to allow to the user to enter passward and save it on check password array
 */
void set_passward()
{
    /*in first clean the screen*/
    HLCD_voidCLRScreen();
    /*if i ==0 thaT mean this is first trial to enter the system*/
    if (i == 0)
    {
        LCD_send_string_pos("PLEASE ENTER PASSWARD...", 0, 0);
    }
    /*else thaT mean this is  not first trial to enter the system*/
    else if (i > 0)
    {
        LCD_send_string_pos("PLEASE ENTER CORRECT PASSWARD...", 0, 0);
    }
    /*intialize number_digit and  index_passward in each time that i call this API */
    number_digit = 0;
    index_passward = 0;

    while (1)
    {
        /* loop until the user click on (ON BUTTON) */
        do
        {
            key_val = keypad_scan(&keypad_1);
        } while (key_val == '\0');
        /*if user click om the (ON BUTTON) stop the functionality */
        if (key_val == '#')
            return;
        number_digit++;
        /*print the number that user enter */
        LCD_Send_Number_Pos(key_val, number_digit, 1);
        _delay_ms(10);
        /*print '*' on the screen  */
        HLCD_voidGoToXy(number_digit, 1);
        HLCD_send_DATA('*');
        /*save the key_value that user enter in screen*/
        check_pass[index_passward] = key_val;
        index_passward++;
    }
}
void run_program(void)
{
    /*diplay the program */
    HLCD_send_command(_LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON);
    /*call this function to get passward from user*/
    set_passward();
    /*if he enter passward clean screen*/
    HLCD_voidCLRScreen();
    /*print loding in the screen*/
    LCD_send_string_pos(" LODING...", 0, 0);
    _delay_ms(100);
    HLCD_voidCLRScreen();
    /* increment i by one to improve that the user use one trial to enter to the system */
    i++;

    while (i < 3)
    {
        /*to check the passward  is correct or not if it correct will make falg_value is one and break*/
        if (Cheack_Password(password_length))
        {
            flagin = 1;
            someone_entered = 1; // to use it in sending function
            break;
        }
        /* increment i by one to improve that the user use one trial to enter to the system */
        i++;
        /*if flag stil zero that mean the user enter wrong passwad so i will ask him to enter the correct password */
        if (flagin == 0)
        {
            set_passward();
            HLCD_voidCLRScreen();
            LCD_send_string_pos(" LODING...", 0, 0);
            _delay_ms(100);
        }
    }
    /*
    if user spend his three trial to guess the correct password
    or know it from first time it will enter this if body
    */
    if (flagin == 1)
    {
        if (index_of_user == 0)
        {
            // Clear UDR register
            UDR = 0;
            UART_void_SendData('O');
        }
        else if (index_of_user == 1)
        {
            // Clear UDR register
            UDR = 0;
            UART_void_SendData('E');
        }
        i = 0;
        flagin = 0;
        HLCD_voidCLRScreen();
        LCD_send_string_pos(" LOGGIN... ", 15, 0);
        _delay_ms(100);
        HLCD_voidCLRScreen();
        LCD_send_string_pos(" YOUR POSITION IS... ", 0, 0);
        LCD_send_string_pos(&(users[index_of_user].position), 1, 1);
        _delay_ms(100);
        HLCD_voidCLRScreen();
        LCD_send_string_pos(" YOUR NAME IS... ", 0, 0);
        LCD_send_string_pos(&(users[index_of_user].name), 1, 1);
        _delay_ms(100);
        HLCD_voidCLRScreen();
        LCD_send_string_pos("THANK YOU... ", 15, 0);
        _delay_ms(100);
        HLCD_voidCLRScreen();
        /*close the system for 50 ms*/
        HLCD_send_command(_LCD_DISPLAY_OFF_CURSOR_OFF);
        _delay_ms(50);
    }
    /*
    if the user spend all trials for remember the password and not know it
    soory i will print the password is wrong and stop system
     */
    else if (flagin == 0)
    {
        // Clear UDR register
        UDR = 0;
        UART_void_SendData('W');
        i = 0;
        HLCD_voidCLRScreen();
        LCD_send_string_pos(" PASSWARD WRONG... ", 0, 0);
        _delay_ms(50);
        /*close the system for 200 ms*/
        HLCD_send_command(_LCD_DISPLAY_OFF_CURSOR_OFF);
        _delay_ms(200);
    }
}
