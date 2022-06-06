#include <iostream>
//basic input output services, such as endl, cout, string
using namespace std;
//allows endl, cout, string to be used without having to repeat 'std::' before each time
char space[3][3]={{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};
// numbers representing the location of a box are sorted neatly into 3x3 rows and columns.
int row;
int column;
char token= 'x';
bool tieGame = false;;
string n1="";
string n2="";
//empty string to represent players' names
void functionOne()
//void functions do not return a value
//this function stylizes the game board
{

    cout<< "     |     |     \n";
    cout<< "  "<<space[0][0]<<"  |  " <<space[0][1]<<   "  |  "<<space[0][2]<<"  \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "  "<<space[1][0]<<"  |  " <<space[1][1]<<   "  |  "<<space[1][2]<<"  \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "  "<<space[2][0]<<"  |  " <<space[2][1]<<   "  |  "<<space[2][2]<<"  \n";
    cout<< "     |     |     \n";
    cout<< "                 \n";
    cout<< "                 \n";
    //this will create a simple tic-tac-toe board with numbers - the numbers make it easier for the user to make a move.
}





void functionTwo(){
//this function collects inputs from each user on their move

    int digit;

    if(token=='x')
    {
        cout<<n1<<" please enter: ";
        cin>>digit;
    }
    //when it is x's turn, they enter their move

    if(token=='0')
    {
        cout<<n2<<" please enter: ";
        cin>>digit;
    }
    //same as above, but for 0

    if(digit==1)
    {
        row=0;
        column=0;
    }
    //gives a value to the number inputed by the user, relative to the number seen on the board.
    if(digit==2)
    {
    row=0;
    column=1;
    }
    if(digit==3)
    {
    row=0;
    column=2;
    }
    if(digit==4)
    {
    row=1;
    column=0;
    }
    if(digit==5)
    {
    row=1;
    column=1;
    }
    if(digit==6)
    {
    row=1;
    column=2;
    }
    if(digit==7)
    {
    row=2;
    column=0;
    }
    if(digit==8)
    {
    row=2;
    column=1;
    }
    if(digit==9)
    {
    row=2;
    column=2;
    }

    else if(digit<1 || digit>9){
        cout<<"Please enter a number between 1f and 9!"<<endl;
        //check for any values which are not within 1-9 to prevent errors.
    }

    if(token=='x' && space[row][column] !='x' && space[row][column] !='0')
    //simple boolean to say if the current player is 'x', and the current space they have selected does not equal x or 0...
{
        space[row][column]='x';
        token='0';
        //then the space becomes x, and the token/current player switches to 0
}
    else if(token=='0' && space[row][column] !='x' && space[row][column] !='0')
{
        space[row][column]='0';
        token='x';
        //same as above, but for 0
}
    else{
        cout<<"That space has already been taken!"<<endl;
        //if the space does equal x or 0, an error message will show up.
        functionTwo();
        //after the error message, function two will run again.
    }
     functionOne();
    //function one (the board) is displayed based on the input from function two

}
bool functionThree()
{
    //this function checks for the status of the game (win, loss, tie)
    for(int i=0;i<3;i++)
    //'i' will represent the row/column number below, to check for a horizontal/vertical tie. Instead of creating an if statement for each possible win combination, letting one value == i works
    {
        if((space[i][0]==space[i][1] && space[i][0]==space[i][2]) || (space[0][i]==space[1][i] && space[0][i]==space[2][i]))
        return true;
        //two possible win combinations, horizontal or vertical. If any one of these operators is true, then a return is true, signaling a game end.
        //this is also why we needed to have each square represent a letter. This statement would not work if each square was left blank (with an automatic win being made)
        //This works because if the value at one space equals the value at another, they are both x or both 0.
    }
    if((space[0][0]==space[1][1] && space[1][1]==space[2][2]) || (space [0][2]==space[1][1] && space[1][1]==space[2][0]))
    //surprisingly, checking for a diagonal tie is also not very complicated. I could have added this same boolean above, but chose to include it in a separate if statement
        //to show that it is a separate type of win. Here, we can not give an 'i' value, as each row and column is unique. However, because there are only two
        //possible win combinations diagonally, this process is much easier than a horizontal/vertical one would be (if 'i' were not used).
    {
        return true;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
            // within the board, if a space does not equal x or 0, the return is false (game does not end). However, this is only if the win has not happened, as seen above.
        }
    }
    tieGame=true;
    //if a tie game, the game must also end.
    return true;
}
int main()
//now, everything above is put into the main section, which will actually make the game appear.
{
    //this following part is not completely necessary, but still fun
    cout<<"Enter the name of the first player: \n";
    getline(cin, n1);
    cout<<"Enter the name of the second player: \n";
    getline(cin, n2);
    cout<<n1<< " is player1 so they will play first \n";
    cout<<n2<< " is player2 so they will play second \n";
    cout<<" the rules are simple - pick a number from 1-9, corresponding to that on the board. Form 3 in a row and you win! \n";

    while(!functionThree())
    //a while loop to create the game, as when the game is not over, it is being played
 {
     functionOne();
     functionTwo();
     functionThree();
     //all three functions work together.
     // //Function one appears first, so that the user can see the board
     //Then comes function two, to allow the user to input a value
     //Then comes function three, to check the value and determine the status of the game.
 }
    if (token =='x' && tieGame == false)
    // if it is the turn of x, that means that 0 has just moved, and if the game is not currently tied (meaning nobody has won) then that means that by process of
        //elimination, 0 has won
    {
        cout<<n2<<" Wins!!"<<endl;

    }
    else if(tieGame== false)
    {
        cout<<n1<<" Wins!!"<<endl;
//for when x wins
    }
    else if(tieGame== true)
    {
        cout<<"It's a draw!"<<endl;
        //if the game ends in a tie, it is a draw, and the game ends.
    }
    cout<<"Thank you for playing!\n";
    cout<<"Rematch?\n";
}
