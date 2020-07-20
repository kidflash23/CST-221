#!/bin/bash
#This is the given bash script which is used to manage users. 
#This takes the input file of usernames, a group name, and an operation flag.
while [ "$RAY" != o ]; do
cat >&2 << MENU

  Enter a variable to launch:
    g - Create a Group Name
    a - Create a Operating Flag
    m - ADD a User
    e - REMOVE a User
    r - Exit
MENU
    printf "\n  Enter your choice: "
    read RAY
    RAY=${Ray,,}
    case $RAY in
        #This gets the given group name and registers it.
        g ) printf "\nWhat would you like the name of the Group to be??\n"
            read -r group_name
            [ -n $group_name ] && touch "$groupname" || \
            printf "error: invalid groupname.\n"
            unset group_name
            ;;

        #This gets the name of the operating flag.
        a ) printf "\nWhat would you like to name your operating flag??\n"
            printf "(including the path to the operating flag location): "
            read -r opp_name
            [ -n $opp_name ] && mkdir -p "$opp_name" || \
            printf "error: invalid directory name.\n"
            unset opp_name
            ;;
  
        #This gets the given name and adds it to the the directory.
        m ) printf "\nEnter a name to register the given user: "
            read -r user_name
            [ -n $user_name ] && useradd $user_name
            unset user_name
            ;;

        #This gets the given name from the directory and removes it.
        e ) printf "\nEnter a name to remove the given user: "
            read -r remove_name
            [ -n $remove_name ] && userdel $remove_name
            unset remove_name
            ;;

        e ) exit 0
            ;;

    esac
done