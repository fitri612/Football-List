#include <iostream>
#include <malloc.h>
// #include <string.h>
using namespace std;


struct column{
    column *next_col;
    column *prev_col;
    string player_name;
    int Count_Col;
    column(){
        next_col = nullptr;
        prev_col = nullptr;
        Count_Col = 0;
    }
};

struct line{
    line *next_line;
    line *prev_line;
    column *col;
    column *End_col;
    int Count_Line;
    string player_Type;
    line(){
        next_line = nullptr;
        prev_line = nullptr;
        col = nullptr;
        End_col = nullptr;
        Count_Line = 0;
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
    // TempLine = (lines)malloc(sizeof(struct line));
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
    // TempCol->player_num = num;
    TempCol->player_name = name;
    return TempCol;
}

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
        // ML->tail = TempLine;
        TempLine->Count_Line++;
        // ++(Temp);
        // temp++;
    }
}

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
        cout << TempLine->col->player_name;
        // TempCol->next_col->prev_col = TempCol;
        // TempCol->prev_col = TempLine;

    }
}

void addLastLine(list *ML, string typeplayer){
    line *TempLine;
    TempLine = AllocationLine(ML, typeplayer);

    if(ML->head == nullptr){
        addBeginLine(ML, typeplayer);
        // ML->head = TempLine;
        // ML->tail = TempLine;
    }
    else{
        ML->tail->next_line = TempLine;
        ML->tail = TempLine;
        // ML->tail->next_line = nullptr;
    }
}

void addLastCol(line *TempLine, string name){

    column *TempCol;
    TempCol = AllocationCol(TempLine, name);

    if(TempLine->col == nullptr){
        addBeginColumn(TempLine, name);
    }
    else{
        TempCol->prev_col = TempLine->End_col;
        TempLine->End_col->next_col = TempCol;
        TempLine->End_col = TempCol;
        // TempLine->End_col->next_col = TempCol;
        // TempCol->prev_col = TempLine->End_col;
        // TempLine->End_col = TempCol;
    }
}


void AddLine(list *ML, string name){
    line * TempLine;
    TempLine = AllocationLine(ML, name);

    if(ML->head == nullptr){
        ML->head = ML->tail = TempLine;
    }
    else{
        line *copy;
        while(copy->next_line != nullptr){
            if(copy == ML->tail ){
                TempLine->next_line = nullptr;
                copy->next_line = TempLine;
                ML->tail = TempLine;
            }
            else{
                TempLine->next_line = copy->next_line;
                copy->prev_line = TempLine;
                if(copy->next_line != nullptr){
                    copy->next_line->prev_line = TempLine;
                }
                copy->next_line = TempLine;
            }
            break;
        }
        copy = copy->next_line;
    }
}

void AddCol(line *TempLine, string name) {
	column *TempCol;
	TempCol = AllocationCol(TempLine, name);
	
	if(TempLine->col == nullptr) {
		TempLine->col = TempLine->End_col= TempCol;
	} else {
		column *copy = TempLine->col;
		string position;
		cout<<"Tambahkan data setelah apa? "; cin>>position;
		while(copy != nullptr) {
			if(copy->player_name == position) {
				TempCol->next_col = copy->next_col;
				TempCol->prev_col = copy;
				if(copy == TempLine->End_col)
					TempLine->End_col = TempCol;
				else
					copy->next_col->prev_col = TempCol;
				copy->next_col = TempCol;
				break;
			}
			copy = copy->next_col;
		}
	}
}


void DelLine(list *ML, string position){
    line *TempLine;
    line *copy;
    if(ML->head->player_Type == position){
        copy = ML->head;
        ML->head = copy->next_line;
        copy->next_line = nullptr;
        // ML->head->prev_line = nullptr;
        cout << "masuk";
        free(copy);
    }
    else if(ML->tail->player_Type == position){
        copy = ML->tail;
        ML->tail = ML->tail->prev_line;
        ML->tail->next_line = nullptr;
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

void DellCol(line *TempLine, string posName){
    column *TempCol;
    column *copy;
    if(TempLine->col->player_name == posName){
        copy = TempLine->col;
        TempLine->col = copy->next_col;
        copy->next_col = nullptr;
        free(copy);
    }
    else{
        copy = TempLine->col;
        while(copy->next_col->next_col != nullptr){
            if(copy->next_col->player_name == posName){
                cout << "masuk";
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

bool checkLine(list *ML, string typePlayer){
    line *TempLine;
    TempLine = ML->head;
    bool check = false;
    while((TempLine != nullptr) && (check == false)){
        if(TempLine->player_Type == typePlayer){
            check = true;
        }
        TempLine = TempLine->next_line;
    }
    return check;
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
    if(checkLine(ML, "striker") == true){
        if(checkPlagiat(ML, name) == false){
            AddCol(TempLine, name);
        }
    }
    else{
        cout << "salah";
    }
}

void AddMidfielder(list *ML, string name){
    line *TempLine = ML->head;
    if(checkLine(ML, "midfielder") == true){
        if(checkPlagiat(ML, name) == false){
            AddCol(TempLine, name);
        }
    }
    else{
        cout << "salah";
    }
}

void AddDefender(list *ML, string name){
    line *TempLine = ML->head;
    if(checkLine(ML, "defender") == true){
        cout << "Masuk";
        if(checkPlagiat(ML, name) == false){
            AddCol(TempLine, name);
        }
    }
    else{
        cout << "salah";
    }

}

// delete col
void DeleteStriker(list *ML, string Dname){
    if(checkLine(ML, "striker")== true){
        line *TempLine = ML->head;
        DellCol(TempLine, Dname);
    }
    else{
        cout << "salah\n";
    }
}

void DeleteMidfielder(list *ML, string Dname){
    if(checkLine(ML, "midfielder")== true){
        line *TempLine = ML->head;
        DellCol(TempLine, Dname);
    }
    else{
        cout << "salah\n";
    }
}

void DeleteDefender(list *ML, string Dname){
    if(checkLine(ML, "defender")== true){
        line *TempLine = ML->head;
        DellCol(TempLine, Dname);
    }
    else{
        cout << "salah\n";
    }   
}

// substitusi
void SubStriker(list *ML, string posName, string CName){
    if(ML->head->player_Type == "striker"){
        if(checkPlagiat(ML, CName) == false){
            line *TempLine = ML->head;
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
}

void SubMidfielder(list *ML, string posName, string CName){
    if(ML->head->player_Type == "midfielder"){
        if(checkPlagiat(ML, CName) == false){
            line *TempLine = ML->head;
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
}

void SubDefender(list *ML, string posName, string CName){
    if(ML->head->player_Type == "defender"){
        if(checkPlagiat(ML, CName) == false){
            line *TempLine = ML->head;
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
}

void SHowAll(list *ML){
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
            while(TempCol != nullptr){
                cout << "\nPlayer Name : " << TempCol->player_name;
                TempCol = TempCol->next_col;
            }
            TempLine = TempLine->next_line;
            i++;
        }
    }
    else{
        cout << "null";
    }
}

void show(list *ML){
    line *TempLine;
    TempLine = ML->head;
    while(TempLine != nullptr){
        if(TempLine->player_Type == "midfielder"){
            cout << "ada mid";
        }
        TempLine = TempLine->next_line;
    }

}

void showStriker(list *ML){
    if(checkLine(ML, "striker") == true){
        // SHowAll(ML);
        cout << "Striker :\n";
        line *TempLine;
        TempLine = ML->head;
        column *TempCol = TempLine->col;
        while(TempCol != nullptr){
            cout << "\nPlayer Name : " << TempCol->player_name;
            TempCol = TempCol->next_col;
        }
    }
    else{
        cout << "false";
    }
}

int main(){
    list *mult;
    // mult = (list*)malloc(sizeof(list));
    mult = new list;
    CreateNewList(mult);
    // addBeginLine(mult, "mii");
    // (mult, "striker");
    addBeginLine(mult, "striker");
    AddStriker(mult, "fitri");
    // cout << "masuk;
    addBeginLine(mult, "midfielder");
    AddMidfielder(mult, "budi");
    // cout << "masuk";
    addBeginLine(mult, "defender");
    AddDefender(mult, "coba");

    show(mult);
    SHowAll(mult);
    return 0;
}
