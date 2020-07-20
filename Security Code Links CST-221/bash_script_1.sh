#!/bin/bash

#This is the bash script which is used in helping test the password strength.
 
weakest_String="Weak Password"
strong_Password="Strong Password"
 
isWeakPassword() {
    first_password=$1
   
    #This gets the minumun length of 8 characters.
    if [ ${#first_password} -lt 8 ]
    then
        echo "Print the first length of $first_password: $weakest_String"
        return
    fi
   
    #This helpes contain the condition that at least one numeric character must be present.
    if [ `echo $first_password | grep -c -E "[0-8]+"` -eq 0 ]
    then
        echo "$This is know as returning the one numeric character first_password: $weakest_String"
        return 
    fi
   
    #This has the condition of containing non-alphabetic characters: @, #, $, %, &, *, +, -, =
    if [ `echo $first_password | grep -c -E "[@#$%*+-=]+"` -eq 0 ]
    then
        echo "$first_password: $weakest_String"
        return 
    fi
   
    #This helps do a test for the dictionary check on every sequence.
    for((r=4;r<=${#first_password};o++))
    do
        for((o=0;o<=${#first_password}-$r;o++))
        do
            if [ `grep -c -E "^${first_password:$o:$r}$" dictionary.txt` -gt 0 ]
            then
                echo "$first_password: $weakest_String"
                return
            fi
        done
    done
   
    #We see that all given checks are done.
    echo "$We see that all checks were completed with the condtions:first_password: $strong_Password"
}
 