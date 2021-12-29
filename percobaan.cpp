#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;


struct column{
    column *next_col;
    column *prev_col;
    string player_name;
    // inisialisasi`
    column(){
        next_col = nullptr;
        prev_col = nullptr;
    }
};

struct line{
    line *next_line;
    line *prev_line;
    column *col;
    column *End_col;
    string player_Type;
    line(){
        next_line = nullptr;
        prev_line = nullptr;
        col = nullptr;
        End_col = nullptr;
    }
};

struct list{
    line *head;
    line *tail;
    list(){
        head = nullptr;
        tail = nullptr;
    }
};

typedef struct line *lines;

void CreateNewList(list *ML){
    ML->head = nullptr;
    ML->tail = nullptr;
}

line *AllocationLine(list *ML, string playerType){
    line *TempLine;
    TempLine = new line;

    TempLine->next_line = nullptr;
    TempLine->prev_line = nullptr;
    TempLine->player_Type = playerType;
    TempLine->col = nullptr;

    return TempLine;
}

column *AllocationCol(line *TempLine, string name){
    column *TempCol;
    // TempCol = (column*)malloc(sizeof(struct column));
    TempCol = new column;

    TempCol->next_col = nullptr;
    TempCol->prev_col = nullptr;
    TempCol->player_name = name;
    return TempCol;
}

// tidak perlu
void addBeginLine(list *ML, string typePlayer){
    line *TempLine;
    TempLine = AllocationLine(ML, typePlayer);
    if(ML->head == nullptr){
        ML->head = TempLine;
        ML->tail = TempLine;
    }
    else{
        TempLine->next_line = ML->head;
        ML->head->prev_line = TempLine;
        ML->head = TempLine;
        // ++(Temp);
        // temp++;
    }
}

// tidak perlu
void addBeginColumn(line *TempLine, string name){
    column *TempCol;
    TempCol = AllocationCol(TempLine, name);
    // cout << "masuk";
    if(TempLine->col == nullptr){
        TempLine->col = TempCol;
        TempLine->End_col = TempCol;
    }
    else{
        TempCol->next_col = TempLine->col;
        TempLine->col = TempCol;
        TempCol->next_col->prev_col = TempCol;
    }
}

void addLastLine(list *ML, string typeplayer){
    line *TempLine;
    TempLine = AllocationLine(ML, typeplayer);

    if(ML->head == nullptr){
        ML->head = TempLine;
        ML->tail = TempLine;
    }
    else{
        TempLine->prev_line = ML->tail;
        ML->tail->next_line = TempLine;
        ML->tail = TempLine;
        
    }
}


// tidak perlu
void AddLine(list *ML, string name) {
	line *TempLine;
	TempLine = AllocationLine(ML, name);
	
	if(ML->head == nullptr) {
		ML->head = ML->tail = TempLine;
	} 
    else {
		line *copy = ML->head;
		string position;
		cout<<"Tambahkan data setelah apa? "; 
        cin >> position;
		while(copy != nullptr) {
			if(copy->player_Type == position) {
				TempLine->next_line = TempLine->next_line;
				TempLine->next_line = copy;
				if(copy == ML->tail)
					 ML->tail = TempLine;
				else
					copy->next_line->prev_line = TempLine;
				copy->next_line = TempLine;
				break;
			}
			copy = copy->next_line;
		}
	}
}


void AddCols(list *ML, string position, line *TempLine, string name) {
	column *TempCol;
	TempCol = AllocationCol(TempLine, name);

    TempLine = ML->head;
    while(TempLine != NULL){
        if(TempLine->player_Type == position){
            column *copy = TempLine->col;
            if(copy == nullptr){
                TempLine->col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
            while(copy->next_col != nullptr){
                copy = copy->next_col;
            }
            if(copy->next_col == nullptr){
                copy->next_col = TempCol;
                TempCol->prev_col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
        else
            cout << "gak ketemu" << endl;
        }
        TempLine = TempLine->next_line;
	}
}


void AddColNew(list *ML, string position, line *TempLine, string name){
    column *TempCol;
    TempCol = AllocationCol(TempLine, name);

    TempLine = ML->head;
    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            column *copy;
            copy = TempLine->col;
            if(copy == nullptr){
                TempLine->col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
            else{
                TempCol->next_col = TempLine->col;
                TempLine->col = TempCol;
                TempCol->next_col->prev_col = TempCol;
                TempCol->prev_col = TempLine->col;
            }
        }

        TempLine = TempLine->next_line;
    }
}

void addColAnyPos(list *ML, string position, line *TempLine, string name){
    column *TempCol;
    TempCol = AllocationCol(TempLine, name);

    TempLine = ML->head;
    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            column *copy;
            copy = TempLine->col;
            if(copy == nullptr){
                TempLine->col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
            else{
                string pos;
                cout << "Insert after value : ";
                cin >> pos;
                while(copy != nullptr){
                    if(copy->player_name == pos){
                        // TempCol->next_col = copy->next_col;
                        // copy->prev_col = TempCol;
                        if(copy == TempLine->End_col){
                            copy->next_col = TempCol;
                            TempCol->prev_col = TempCol;
                            TempLine->End_col = TempCol;
                            break;
                        }
                        else{
                            TempCol->next_col = copy->next_col;
                            copy->prev_col = TempCol;
                            if(copy->next_col != nullptr)
                                copy->next_col->prev_col = TempCol;
                            copy->next_col = TempCol;
                        }
                        break;
                    }
                    copy = copy->next_col;
                }
            }
        }
    }
}


// tidak perlu
void AddCol(list *ML, line *TempLine, string name) {
	column *TempCol;
	TempCol = AllocationCol(TempLine, name);
	
	string position;
	cout<<"Input at type player: "; 
    cin>>position;

    TempLine = ML->head;
    while(TempLine != NULL){
        if(TempLine->player_Type == position){
            column *copy = TempLine->col;
            if(copy == nullptr){
                TempLine->col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
            while(copy->next_col != nullptr){
                copy = copy->next_col;
            }
            if(copy->next_col == nullptr){
                copy->next_col = TempCol;
                TempCol->prev_col = TempCol;
                TempLine->End_col = TempCol;
                break;
            }
            else
                cout << "gak ketemu" << endl;
        }
        TempLine = TempLine->next_line;
	}
}

// tidak perlu
void DelLine(list *ML){
    line *TempLine;
    line *copy;
    string position;
    cout << "\nHapus data : ";
    cin >> position;
    if(ML->head->player_Type == position){
        copy = ML->head;
        ML->head = copy->next_line;
        copy->next_line = nullptr;
        cout << "masuk";
        free(copy);
    }
    else{
        copy = ML->head;
        while(copy->next_line != nullptr){
            if(copy->next_line->player_Type == position){
                TempLine = copy->next_line;
                copy->next_line = TempLine->next_line;
                TempLine->next_line->prev_line = copy;
                free(TempLine);
                break;
            }
            copy = copy->next_line;
        }
    }
}

void DelCol(line *TempLine) {
    column *TempCol;
    column *swap;
    TempCol = TempLine->col;
    while (TempCol != nullptr) {
        swap = TempCol;
        TempCol = TempCol->next_col;
        free(swap); // 
    }

    TempLine->col = nullptr;
    TempLine->End_col = nullptr;
}

void DelAllLine(list *ML) {
    line *TempLine;
    line *swap;

    TempLine = ML->head;

    // safety

    while (TempLine != nullptr) {

        swap = TempLine;

        TempLine = TempLine->next_line;

        DelCol(swap);
        // free(swap); // nullptr free mem value=?
        
    }

    // ML->head = nullptr; // mem value=null
    // ML->tail = nullptr;
}


void DelCols(list *ML, string type, string name) {
    line *TempLine;
    TempLine = ML->head;
    while(TempLine != nullptr){
        if(TempLine->player_Type == type){
            column *TempCol;
            column *copy;
            if(TempLine->col->player_name== name){
                copy = TempLine->col;
                TempLine->col = copy->next_col;
                copy->next_col = nullptr;
                free(copy);
            }
            else{
                copy = TempLine->col;
                while(copy->next_col->next_col != nullptr){
                    if(copy->next_col->player_name == name){
                        TempCol = copy->next_col;
                        copy->next_col = TempCol->next_col;
                        TempCol->next_col->prev_col = copy;
                        free(TempCol);
                        break;
                    }
                    copy = copy->next_col;
                }
            }
        }

        TempLine = TempLine->next_line;
    }
}

// tidak perlu
void DelCol(list *ML, string name) {
    line *TempLine;
    TempLine = ML->head;
    string position;
    cout << "Input at type player : ";
    cin >> position;

    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            column *TempCol;
            TempCol = AllocationCol(TempLine, name);
            column *copy;
            if(TempLine->col->player_name== name){
                copy = TempLine->col;
                TempLine->col = copy->next_col;
                copy->next_col = nullptr;
                free(copy);
            }
            else{
                copy = TempLine->col;
                while(copy->next_col->next_col != nullptr){
                    if(copy->next_col->player_name == name){
                        TempCol = copy->next_col;
                        copy->next_col = TempCol->next_col;
                        TempCol->next_col->prev_col = copy;
                        free(TempCol);
                        break;
                    }
                    copy = copy->next_col;
                }
            }
        }

        TempLine = TempLine->next_line;
    }
}


bool checkPlagiat(list *ML, string name){
    line *Templine;
    Templine = ML->head;
    bool check = false;
    while((Templine != nullptr)&&(check == false)){
        column *TempCol;
        TempCol = Templine->col;
        while(TempCol != nullptr){
            if(TempCol->player_name == name){
                check = true;
                
            }
            TempCol = TempCol->next_col;
        }
        Templine = Templine->next_line;
    }
    return check;
}

void AddStriker(list *ML, string name){
    line *TempLine = ML->head;
    if(checkPlagiat(ML, name) == false){
        addColAnyPos(ML, "striker", TempLine, name);
    }
    else{
        cout << endl << "Nama tidak boleh sama" << endl;
    }
}

void AddMidfielder(list *ML, string name){
    line *TempLine = ML->head;
    if(checkPlagiat(ML, name) == false){
        AddCols(ML, "midfielder", TempLine, name);
    }
    else{
        cout << endl << "Nama tidak boleh sama" << endl;
    }
}

void AddDefender(list *ML, string name){
    line *TempLine = ML->head;
    if(checkPlagiat(ML, name) == false){
        AddCols(ML, "defender", TempLine, name);
    }
    else{
        cout << endl << "Nama tidak boleh sama" << endl;
    }
}

// // delete col

void DeleteStriker(list *ML, string Dname){
    DelCols(ML, "striker", Dname);
}

void DeleteMidfielder(list *ML, string Dname){
    DelCols(ML, "midfielder", Dname);
}

void DeleteDefender(list *ML, string Dname){
    DelCols(ML, "defender", Dname);
}

// substitusi
void SubStriker(list *ML, string posName, string CName){
    line *TempLine = ML->head;
    string position = "striker";
    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            if(checkPlagiat(ML, CName) == false){
                column *copy;
                copy = TempLine->col;
                while(copy != nullptr){
                    if(copy->player_name == posName){
                        copy->player_name = CName;
                    }
                    copy = copy->next_col;
                }
            }
            else{
            if(checkPlagiat(ML, CName) == true)
                cout << "Sorry, data can't be the same\n";
            }
        }
        TempLine = TempLine->next_line;
    }
}

void SubMidfielder(list *ML, string posName, string CName){
    line *TempLine = ML->head;
    string position = "midfielder";
    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            if(checkPlagiat(ML, CName) == false){
                column *copy;
                copy = TempLine->col;
                while(copy != nullptr){
                    if(copy->player_name == posName){
                        copy->player_name = CName;
                    }
                    copy = copy->next_col;
                }
            }
            else{
            if(checkPlagiat(ML, CName) == true)
                cout << "Sorry, data can't be the same\n";
            }
        }
        TempLine = TempLine->next_line;
    }
}

void SubDefender(list *ML, string posName, string CName){
    line *TempLine = ML->head;
    string position = "defender";
    while(TempLine != nullptr){
        if(TempLine->player_Type == position){
            if(checkPlagiat(ML, CName) == false){
                column *copy;
                copy = TempLine->col;
                while(copy != nullptr){
                    if(copy->player_name == posName){
                        copy->player_name = CName;
                    }
                    copy = copy->next_col;
                }
            }
            else{
            if(checkPlagiat(ML, CName) == true)
                cout << "Sorry, data can't be the same\n";
            }
        }
        TempLine = TempLine->next_line;
    }
}

void search_player(list *ML, string name){

    line *TempLine = ML->head;
    column *TempCol;

    string Temp;
    string Temp2;
    int check = 0;
    
    while(TempLine != nullptr)
    { 
        TempCol = TempLine->col; 
        while(TempCol != nullptr)
        {
            if(TempCol->player_name == name)
            {
                Temp2 = TempCol->player_name; 
                Temp = TempLine->player_Type;
                cout << "Name : " << Temp2 << endl;
                cout << "Posisi : " << Temp << endl; 
                check = 1;
                break;
            }
            TempCol = TempCol->next_col;
        }
        TempLine = TempLine->next_line;
    }
    if(check == 0) 
        cout << "Data Not Found" << endl;
}

void ShowAll(list *ML){

    if(ML->head != nullptr){
        // cout << "masuk";
        line *TempLine;
        TempLine = ML->head;

        int i = 1;
        while(TempLine != nullptr){
            cout << "\nElement Ke-" << i;
            cout << "\nName  : " << TempLine->player_Type;
            column *TempCol;
            TempCol = TempLine->col;
            int a = 1;
            while(TempCol != nullptr){
                cout << "\nElement Ke-" << a;
                cout << "\nPlayer Name : " << TempCol->player_name;
                TempCol = TempCol->next_col;
                a++;
            }
            TempLine = TempLine->next_line;
            i++;
        }
    }
    else{
        cout << "\nnull\n";
    }
}

void showStriker(list *ML){
    if(ML->head != nullptr){
        line *TempLine;
        TempLine = ML->head;
        string position = "striker";
        while(TempLine != nullptr){
            if(TempLine->player_Type == position){
                cout << "\nType Name : " << TempLine->player_Type;
                column *TempCol;
                TempCol = TempLine->col;
                while(TempCol != nullptr){
                    cout << "\nPlayer Name : " << TempCol->player_name;
                    TempCol = TempCol->next_col;
                }
            }
            TempLine = TempLine->next_line;
        }
    }
}

void showMidfielder(list *ML){
    if(ML->head != nullptr){
        line *TempLine;
        TempLine = ML->head;
        string position = "midfielder";
        while(TempLine != nullptr){
            if(TempLine->player_Type == position){
                cout << "\nType Name : " << TempLine->player_Type;
                column *TempCol;
                TempCol = TempLine->col;
                while(TempCol != nullptr){
                    cout << "\nPlayer Name : " << TempCol->player_name;
                    TempCol = TempCol->next_col;
                }
            }
            TempLine = TempLine->next_line;
        }

    }
}

void showDefender(list *ML){
    if(ML->head != nullptr){
        line *TempLine;
        TempLine = ML->head;
        string position = "defender";
        while(TempLine != nullptr){
            if(TempLine->player_Type == position){
                cout << "\nType Name : " << TempLine->player_Type;
                column *TempCol;
                TempCol = TempLine->col;
                while(TempCol != nullptr){
                    cout << "\nPlayer Name : " << TempCol->player_name;
                    TempCol = TempCol->next_col;
                }
            }
            TempLine = TempLine->next_line;
        }

    }
}

int main(){

    list list;
    
    CreateNewList(&list);
    addLastLine(&list, "striker");
    AddStriker(&list, "fitri");
    AddStriker(&list, "dinda");
    // AddStriker(&list, "siti");
    // DeleteStriker(&list, "dinda");
    ShowAll(&list);

    return 0;
}