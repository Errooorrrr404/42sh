#!/bin/bash

##
## EPITECH PROJECT, 2019
## PSU_42sh_2018
## File description:
## tests
##

exec 2>/dev/null
ls -al test

make

tests_passed=0
tests_failed=0


echo -e "\e[100mBuiltins\e[0m"


# EXIT
exit="exit"
exit_shell=$(echo "exit" | ./42sh)
if [[ $exit_shell =~ $exit ]]
then
    echo -e "\e[32mEXIT: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mEXIT: NO\e[0m"
    let "tests_failed+=1"
fi


# BAD EXIT
badexit=$(echo "exit l" | tcsh)
badexit_shell=$(echo "exit l" | ./42sh)
if [[ $badexit_shell =~ $badexit ]]
then
    echo -e "\e[32mBAD EXIT: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mBAD EXIT: NO\e[0m"
    let "tests_failed+=1"
fi


# EXIT WITH NB
nbexit=$(echo "exit 84 ; echo $?" | tcsh)
nbexit_shell=$(echo "exit 84" | ./42sh ; echo $?)
if [[ $nbexit_shell =~ $nbexit ]]
then
    echo -e "\e[32mEXIT WITH NB: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mEXIT WITH NB: NO\e[0m"
    let "tests_failed+=1"
fi


# CD
cd=$(cd ; pwd)
cd_shell=$((echo "cd" ; echo "pwd") | ./42sh)
if [[ $cd_shell =~ $cd ]]
then
    echo -e "\e[32mCD: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mCD: NO\e[0m"
    let "tests_failed+=1"
fi


# CD ..
cd=$(cd .. ; pwd)
cd_shell=$((echo "cd .." ; echo "pwd") | ./42sh)
if [[ $cd_shell =~ $cd ]]
then
    echo -e "\e[32mCD ..: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mCD ..: NO\e[0m"
    let "tests_failed+=1"
fi


# CD FOLDER
cdfile=$(cd src ; pwd)
cdfile_shell=$((echo "cd src" ; echo "pwd") | ./42sh)
if [[ $cdfile_shell =~ $cdfile ]]
then
    echo -e "\e[32mCD FOLDER: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mCD FOLDER: NO\e[0m"
    let "tests_failed+=1"
fi


# ENV
env=$(echo env | tcsh)
env_shell=$(echo env | ./42sh)
if [[ $env_shell =~ $env ]]
then
    echo -e "\e[32mENV: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mENV: NO\e[0m"
    let "tests_failed+=1"
fi


# SETENV
setenv=$(setenv a b ; env)
setenv_shell=$((echo "setenv a b" ; echo "env") | ./42sh)
if [[ $cdfile_shell =~ $cdfile ]]
then
    echo -e "\e[32mSETENV: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mSETENV: NO\e[0m"
    let "tests_failed+=1"
fi


# UNSETENV
unsetenv=$(setenv a b ; unsetenv a; env)
unsetenv_shell=$((echo "setenv a b" ; echo "unsetenv a b" ; echo "env") | ./42sh)
if [[ $cdfile_shell =~ $cdfile ]]
then
    echo -e "\e[32mUNSETENV: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mUNSETENV: NO\e[0m"
    let "tests_failed+=1"
fi


# ALIAS
alias=$(ls)
alias_shell=$((echo "alias a ls" ; echo "a") | ./42sh)
if [[ $alias_shell =~ $alias ]]
then
    echo -e "\e[32mALIAS: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mALIAS: NO\e[0m"
    let "tests_failed+=1"
fi


echo ""
echo -e "\e[100mErrors and formatting\e[0m"


# WRONG COMMAND
wrong=$(azertyuiop)
wrong_shell=$(echo "azertyuiop" | ./42sh)
if [[ $wrong_shell =~ $wrong ]]
then
    echo -e "\e[32mWRONG COMMAND: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mWRONG COMMAND: NO\e[0m"
    let "tests_failed+=1"
fi


# LINE FORMATING
lf=$("ls                   \t                        -R")
lf_shell=$(echo "ls                      \t                      -R" | ./42sh)
if [[ $lf_shell =~ $lf ]]
then
    echo -e "\e[32mLINE FORMAT: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mLINE FOMAT: NO\e[0m"
    let "tests_failed+=1"
fi


# WRONG CD
wrongcd=$(echo "cd azertyuiop" | tcsh)
wrongcd_shell=$(echo "cd azertyuiop" | ./42sh)
if [[ $wrongcd_shell =~ $wrongcd ]]
then
    echo -e "\e[32mWRONG CD (NO SUCH FILE): OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mWRONG CD (NO SUCH FILE): NO\e[0m"
    let "tests_failed+=1"
fi


# WRONG CD
wrongcdndir=": Not a directory."
wrongcdndir_shell=$(echo "cd .gitignore" | ./42sh)
if [[ $wrongcdndir_shell =~ $wrongcdndir ]]
then
    echo -e "\e[32mWRONG CD (NOT A DIR): OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mWRONG CD (NOT A DIR): NO\e[0m"
    let "tests_failed+=1"
fi


echo ""
echo -e "\e[100mRedirections and pipes\e[0m"


# RIGHT REDIRECTION
rredir=$(ls > toto ; cat toto ; rm toto)
rredir_shell=$(echo "ls > toto" | ./42sh ; cat toto)
if [[ $rredir_shell =~ $rredir ]]
then
    echo -e "\e[32mRIGHT REDIR: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mRIGHT REDIR: NO\e[0m"
    let "tests_failed+=1"
fi
rm toto
rm titi


# DOUBLE RIGHT REDIRECTION
touch toto ; pwd > toto
touch titi ; pwd > titi
drredir=$(pwd >> toto ; cat toto)
drredir_shell=$(echo "pwd >> titi" | ./42sh ; cat titi)
if [[ $drredir_shell =~ $drredir ]]
then
    echo -e "\e[32mDOUBLE RIGHT REDIR: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mDOUBLE RIGHT REDIR: NO\e[0m"
    let "tests_failed+=1"
fi
rm toto
rm titi


echo ""
echo -e "\e[100mSimple commands\e[0m"


# PWD (SIMPLE COMMAND)
pwd=$(pwd)
pwd_shell=$(echo "pwd" | ./42sh)
if [[ $pwd_shell =~ $pwd ]]
then
    echo -e "\e[32mPWD: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mPWD: NO\e[0m"
    let "tests_failed+=1"
fi


# LS (SIMPLE COMMAND)
ls=$(ls)
ls_shell=$(echo "ls" | ./42sh)
if [[ $ls_shell =~ $ls ]]
then
    echo -e "\e[32mLS: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mLS: NO\e[0m"
    let "tests_failed+=1"
fi


echo ""
echo -e "\e[100mOperators\e[0m"


# OR
or=$(bruh || ls || bruh)
or_shell=$(echo "bruh || ls || bruh" | ./42sh)
if [[ $or_shell =~ $or ]]
then
    echo -e "\e[32mOR (||): OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mOR (||): NO\e[0m"
    let "tests_failed+=1"
fi


# and (&&)
and=$(ls && pwd && azertyuiop && ls)
and_shell=$(echo "ls && pwd && azertyuiop && ls" | ./42sh)
if [[ $and_shell =~ $and ]]
then
    echo -e "\e[32mAND (&&): OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mAND (&&): NO\e[0m"
    let "tests_failed+=1"
fi


# or and mix
and=$(azz || pwd && ls)
and_shell=$(echo "azz || pwd && ls" | ./42sh)
if [[ $and_shell =~ $and ]]
then
    echo -e "\e[32mAND & OR: OK\e[0m"
    let "tests_passed+=1"
else
    echo -e "\e[31mAND & OR: NO\e[0m"
    let "tests_failed+=1"
fi

echo ""
echo -e "\e[42m$tests_passed tests passed\e[0m"
echo -e "\e[101m$tests_failed tests failed\e[0m"