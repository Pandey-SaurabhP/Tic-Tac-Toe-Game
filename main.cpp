// This game is completely made by Saurabh Pandey alone...


#include <iostream>
#include <string>
#include <cstdlib>

#define p(x) std::cout << x << std::endl;

using namespace std;

string check(char board[9], string P1, string P2)
{
	for (int i = 0; i < 3; ++i)
	{
		if (board[i] == 'X' &&
			board[i] == board[i+3] &&
			board[i] == board[i+6])
		{
			return P1;
		}
	}
	for (int i = 0; i < 9; i = i + 3)
	{
		if (board[i] == 'X' &&
			board[i] == board[i + 1] &&
			board[i] == board[i + 2])
		{
			return P1;
		}
	}
	if (board[0] == 'X' &&
		board[0] == board[4] &&
		board[4] == board[8] ||
		board[6] == 'X' &&
		board[6] == board[4] &&
		board[6] == board[2])
	{
		return P1;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (board[i] == 'O' &&
			board[i] == board[i+3] &&
			board[i] == board[i+6])
		{
			return P2;
		}
	}
	for (int i = 0; i < 9; i = i + 3)
	{
		if (board[i] == 'O' &&
			board[i] == board[i + 1] &&
			board[i] == board[i + 2])
		{
			return P2;
		}
	}
	if (board[0] == 'O' &&
		board[0] == board[4] &&
		board[4] == board[8] ||
		board[6] == 'O' &&
		board[6] == board[4] &&
		board[6] == board[2])
	{
		return P2;
	}
	return "0";
}

void print_board(char board[9])
{
	cout << "\n\n";
	cout << "        |     |     " << endl;
	cout << "     " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "   \n";
	cout << "   _____|_____|_____\n";
	cout << "        |     |     " << endl;
	cout << "     " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "   \n";
	cout << "   _____|_____|_____\n";
	cout << "        |     |     " << endl;
	cout << "     " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "   \n";
	cout << "        |     |     \n\n";
	cout << "_ __ _ __ _ __ _ __ _ __ _\n";
}

int invalid_move(int cell)
{
	if (cell >= 0 && cell < 9)
	{
		return 0;
	}

	else
	{
		cout << "Invalid Move..Try again\n";
		cout << "Your turn again:";
	    cin >> cell;
	    cell--;
	    return invalid_move(cell);
	}
}

int invalid_move_2(char board[9], int cell)
{
	if(board[cell] != ' ')
	{
		cout << "The cell is already taken by another player...\n";
		cout << "Please try again:";
		cin >> cell;
		cell--;
		return invalid_move_2(board, cell);
	}
	else
	{
		return cell;
	}
}

int invalid_move_C(char board[9], int cell)
{
	if(board[cell] != ' ')
	{
		cell = (rand() % 9) + 1;
		cell--;
		return invalid_move_C(board, cell);
	}
	else
	{
		return cell;
	}
}

void help()
{
	system("cls");
	p("Hello Everyone")
	p("Its the basic Tic-Tac-Toe game noooo..")
	p("")
	p("Here, you have to insert a number from 1 to 9.")
	p("And an X or O will get inserted in the blocks using the following rule..")
	p("     |     |     ")
	p("  1  |  2  |  3  ")
	p("_____|_____|_____")
	p("     |     |     ")
	p("  4  |  5  |  6  ")
	p("_____|_____|_____")
	p("     |     |     ")
	p("  7  |  8  |  9  ")
	p("     |     |     ")
	p("Press Enter for Main Menu...")
	cin.get();
	cin.get();
	system("cls");

}

int main()
{
	char inp, a = 'A';

    while (a == 'A' || a == 'a')
    {
    	char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

        cout << "This game is entirely made by Saurabh Pandey...\n";
		cout << "Welcome to Tic-Tac-toe...\n\n";
		cout << "Press S for Single-Player..." << endl;
		cout << "Press M for Multiplayer..." << endl;
		cout << "        or        " << endl;
		cout << "Press H for Help.." << endl;
		cout << "        or        " << endl;
		cout << "Press X to Exit..." << endl;
		cout << "Enter your key:";
		cin >> inp;

        if (inp == 'H' || inp == 'h')
        {
        	help();
        	continue;
        }

		if (inp == 'X' || inp == 'x')
		{
			break;
		}

		if(inp == 'S' || inp == 's')
		{
			system("cls");

	    	string P1, P2 = "Computer";
	    	cout << "Please Enter your name:";
	    	cin >> P1;

	    	system("cls");
		    int cell;

			for (int i = 1; i <= 4; i++)
			{
			    print_board(board);
			    cout << endl;
				cout << P1 << "'s turn::Enter the cell:";
				cin >> cell;
				cell--;

				invalid_move(cell);
				cell = invalid_move_2(board, cell);
				board[cell] = 'X';
				if (check(board, P1, P2) != "0")
				{
					system("cls");
					cout << check(board, P1, P2) << " wins";
					cin.get();
					goto end2;
				}
				system("cls");

				cin.get();
			    system("cls");


			    print_board(board);
			    cout << endl;
	            cout << "Please Wait...";
				int cell = (rand() % 9) + 1;
				cell--;

				cell = invalid_move_C(board, cell);
                board[cell] = 'O';
                if (check(board, P1, P2) != "0")
				{
					system("cls");
					cout << check(board, P1, P2) << " wins";
					goto end2;
				}
                system("cls");
		    }

        system("cls");

		print_board(board);
    	cout << "\n" << P1 << "'s turn::Enter the cell:";
		cin >> cell;
		cell--;

		invalid_move(cell);
		cell = invalid_move_2(board, cell);
		system("cls");
		board[cell] = 'X';
		if (check(board, P1, P2) != "0")
		{
			system("cls");
			cout << check(board, P1, P2) << " wins";
			cin.get();
		}
		end2:
		print_board(board);
		cout << "\nFinal board is here...\nPress Enter...";
		cin.get();
	    system("cls");
	    }

		if (inp == 'M' || inp == 'm')
	    {
	    	system("cls");
	    	string P1, P2;
	    	cout << "Player 1 name is:";
	    	cin >> P1;
	    	cout << "Player 2 name is:";
	    	cin >> P2;
	    	system("cls");
		    int cell;

			for (int i = 1; i <= 4; i++)
			{

			    print_board(board);
			    cout << endl;
				cout << P1 << "'s turn::Enter the cell:";
				cin >> cell;
				cell--;

				invalid_move(cell);
				cell = invalid_move_2(board, cell);
				board[cell] = 'X';
				if (check(board, P1, P2) != "0")
				{
					system("cls");
					cout << check(board, P1, P2) << " wins";
					cin.get();
					goto end1;
				}

				cin.get();
			    system("cls");



			    print_board(board);
			    cout << endl;
				cout << P2 << "'s turn::Enter the cell:";
				cin >> cell;
				cell--;

				invalid_move(cell);
				cell = invalid_move_2(board, cell);
				board[cell] = 'O';
				if (check(board, P1, P2) != "0")
				{
					system("cls");
					cout << check(board, P1, P2) << " wins";
					cin.get();
					goto end1;
				}

				cin.get();
			    system("cls");
			}


			print_board(board);
			cout << "\n" << P1 << "'s turn::Enter the cell:";
			cin >> cell;
			cell--;

			invalid_move(cell);
			cell = invalid_move_2(board, cell);

			system("cls");
			board[cell] = 'X';
			if (check(board, P1, P2) != "0")
			{
				system("cls");
				cout << check(board, P1, P2) << " wins";
				cin.get();
			}
			end1:
			print_board(board);
			cout << "\nFinal board is here...\nPress Enter...";
			cin.get();
		    system("cls");
	    }

	    end:

	    cout << "Thanks for playing...\n\n\n";
	    cout << "Press A to play again...\n";
	    cout << "Any other key to exit...";
	    cin >> a;
	    system("cls");
    }

    system("cls");
	cout << "Thanks for playing...\nBye-Bye...\n\n";
	cin.get();

	return 0;
}
