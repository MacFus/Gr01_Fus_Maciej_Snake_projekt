#include "functions.h"

bool gameOver;
bool wall = true;
int width = 25;
int height = 25;
int lvl = 3;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int tailX[100], tailY[100], nTail;

void arrow(int currentPosition, int arrowPosition)
{
	if (currentPosition == arrowPosition) {
		cout << "-->  ";
	}
	else {
		cout << " ";
	}
}
// glowne menu, opcje, trudnosc, sciany, predkosc
int menu() 
{
	int position = 1;
	int key = 0;

	while (true) //13 to enter
	{
		system("cls");

		arrow(1, position);	 cout << "START" << endl;
		arrow(2, position);	 cout << "OPTIONS" << endl;
		arrow(3, position);	 cout << "QUIT" << endl;

        cout <<endl <<"Next -> ENTER\t\t Back -> ESC" << endl;

		key = _getch();

		if (key == 80 && position != 3) {	//strzalka w dol
			position++;
		}
		else if (key == 72 && position != 1 ){ //strzalka w gore
		
			position--;
		}
		else{
			position = position;
		}

        if (key == 13)
        {
            return position;
        }

        if (key == 27)
        {
            return 3;
        }
	}
}
//opcje z menu, rozgalezienia
int difficulty() {
    int positionD = 1;
    int keyD = 0;

    while (true) 
    {
        system("cls");

        arrow(1, positionD);	 cout << "EASY" << endl;
        arrow(2, positionD);	 cout << "NORMAL" << endl;
        arrow(3, positionD);	 cout << "HARD" << endl;

        cout << endl << "Next -> ENTER\t\t Back -> ESC" << endl;

        keyD = _getch();

        if (keyD == 80 && positionD != 3) {	//strzalka w dol
            positionD++;
        }
        else if (keyD == 72 && positionD != 1) { //strzalka w gore

            positionD--;
        }
        else {
            positionD = positionD;
        }

        if (keyD == 13)
        {
            if (positionD == 1)
            {
                lvl = 1;
            }
            else if (positionD == 2)
            {
                lvl = 2;
            }
            else if (positionD == 3)
            {
                lvl = 3;
            }
            return 3;
        }

        if (keyD == 27)
        {
            return 3;
        }
    }
}
int wallEffects() {

    int positionOptions = 1;
    int keyOptrions = 0;

    while (true) //13 to enter
    {
        system("cls");

        arrow(1, positionOptions);	 cout << "TURN ON WALLS" << endl;
        arrow(2, positionOptions);	 cout << "TURN OFF WALLS" << endl << endl << endl;
        //   arrow(3, positionOptions);	 cout << "Speed" << endl;

        cout << "Next -> ENTER\t\t Back -> ESC" << endl;


        keyOptrions = _getch();

        if (keyOptrions == 80 && positionOptions != 2) {	//strzalka w dol
            positionOptions++;
        }
        else if (keyOptrions == 72 && positionOptions != 1) { //strzalka w gore

            positionOptions--;
        }
        else {
            positionOptions = positionOptions;
        }

        if (keyOptrions == 13)
        {
            if (positionOptions == 1)
            { 
                wall = true;
            }
            else if (positionOptions == 2)
            {
                wall = false;
            }
            return 3;
        }
        else if (keyOptrions == 27)
        {
            return 3;
        }
    }
}
int options()
{
    int positionOptions = 1;
    int keyOptrions = 0;

    while (true) //13 to enter
    {
        system("cls");

        arrow(1, positionOptions);	 cout << "DIFFICULTY" << endl;
        arrow(2, positionOptions);	 cout << "WALL EFFECTS" << endl;
        arrow(3, positionOptions);	 cout << "BOARD SIZE" << endl << endl;;

        cout << "Next -> ENTER\t\t Back -> ESC" << endl;

        keyOptrions = _getch();

        if (keyOptrions == 80 && positionOptions != 3) {	//strzalka w dol
            positionOptions++;
        }
        else if (keyOptrions == 72 && positionOptions != 1) { //strzalka w gore

            positionOptions--;
        }
        else {
            positionOptions = positionOptions;
        }

        if (keyOptrions == 13)
        {
            if (positionOptions == 1)
            {
                return difficulty();
            }
            else if (positionOptions == 2)
            {
                return wallEffects();
            }
            else if (positionOptions == 3)
            {
                return boardSize();
            }


        }else if (keyOptrions == 27)
        {
            return 3;
        }
    }
}
int boardSize() {
    int keyOperations = 0;
    cout << "Choose board size." << endl;
    cout << "Width: ";
    cin >> width;
    cout <<  "Height: ";
    cin >> height;
    if (keyOperations == 27)
        {
        return 3;
        }
}
//kazdorazowo wywolywane w glownej funkcji programu
void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = 1 + rand() % (width -2);
    fruitY = 1 + rand() % (height-2);
    score = 0;
    nTail = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width + 1; i++)
    {
        cout << '#';
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << '#';
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        print = true;
                        cout << 'o';
                    }
                }
                if (!print)
                    cout << ' ';
            }

            if (j == width - 1)
                cout << '#';
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << '#';
    }
    cout << endl;
    cout << "Score: " << score << endl;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            //case 'p':
            //    dir = STOP;
            //    break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
int logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (wall) {
        if (x < 0 || x > width || y < -1 || y > height)
        {
            gameOver = true;
            getchar();
            cout << "You've lost" << endl << "Enter any key" << endl;
            getchar();
            return menu();
        }
    }
    else
    {
        if (x < 0)
            x = width;
        else if (x > width)
            x = 0;
        else if (y < 0)
            y = height - 1;
        else if (y > height)
            y = 0;
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX =1 + rand() % (width-2);
        fruitY =1 + rand() % (height-2);
        nTail++;
    }
    for (int k = 0; k < nTail; k++)
    {
        if (tailX[k] == x && tailY[k] == y)
        {
            cout << getchar() << "You ate yourself!" << getchar()<< endl;
            gameOver = true;
            return menu();
        }
    }        
}   
void slp(int lvl)
{
    if (lvl == 1) {
        Sleep(100);
    }
    else if (lvl == 2) {
        Sleep(50);
    }
    else if (lvl == 3) {
        Sleep(10);
    }
}
//glowna funkcja
void game()
{
    int state;
    while (true)
    {
        state = menu();

        switch (state)
        {
        case 1:
            setup();
            while (!gameOver)
            {
                draw();
                input();
                logic();
                slp(lvl);
            }
            break;
        case 2:
            options();
            break;
        case 3:
            return;
        }
    }
}
