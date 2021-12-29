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
    TempCol->prev_col = TempLine->col;
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
        AddCols(ML, "striker", TempLine, name);
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


void showMenu(){
    cout << "\n================================================\n";
    cout << "================ MENU FORMATION ================\n";
    cout << "================================================\n";
    cout << "[1] 3 - 4 - 3 \n";
    cout << "[2] 3 - 5 - 2 \n";
    cout << "[3] 4 - 3 - 3 \n";
    cout << "[4] 4 - 4 - 2 \n";
    cout << "[5] 4 - 2 - 4 \n";
    cout << "[6] 4 - 5 - 1 \n";
    cout << "[7] 5 - 3 - 2 \n";
    cout << "[8] Exit\n";    
    cout << "Insert your option formation : ";
}

void MenuPemain(){
    cout << "================ MENU PEMAIN ================\n";
    cout << "[01] tambah_striker" << endl;
    cout << "[02] hapus_striker" << endl;
    cout << "[03] tambah_midfielder" << endl;
    cout << "[04] hapus_midfielder" << endl;
    cout << "[05] tambah_defender" << endl;
    cout << "[06] hapus_defender" << endl;
    cout << "[07] subtitusi_striker" << endl;
    cout << "[08] subtitusi_midfielde" << endl;
    cout << "[09] subtitusi_defende" << endl;
    cout << "[10] tampil_striker" << endl;
    cout << "[11] tampil_midfielder" << endl;
    cout << "[12] tampil_defende" << endl;
    cout << "[13] tampil_pemain" << endl;
    cout << "[14] hapus_pemain" << endl;
    cout << "[15] cari_pemain" << endl;
    cout << "[16] kembali" << endl;
    cout << "[17] exit" << endl;

    cout << "Insert your option : ";
}

void step1(list *mut, int striker_max, int mid_max, int defender_max) {

    int x = 0;
    int striker_count = 0;
    int mid_count = 0;
    int defender_count = 0;

    addLastLine(mut, "striker");
    addLastLine(mut, "midfielder");
    addLastLine(mut, "defender");

    while (true) {

        MenuPemain();
        int opt;
        cin >> opt;

        if (opt == 1 ) {

            x = striker_count;
            for (int i = 1; i <= (striker_max - x); i++) {

                string nama;
                cout << "[" << i << "] Insert player name :";
                cin >> nama;
                AddStriker(mut, nama); 
                striker_count += 1;
            
            };
        }
        else if (opt == 2 ) {

            if (striker_count > 0) {
                
                string nama;
                cout << "Insert player name :";
                cin >> nama;
                DeleteStriker(mut, nama); 
                striker_count -= 1;

            } else {

                cout << "Data empty" << endl;
                
            }
        }
        else if (opt == 3 ) {
            
            x = mid_count;
            for (int i = 1; i <= (mid_max - x); i++) {
                string nama;
                cout << "[" << i << "] Insert player name :";
                cin >> nama;
                AddMidfielder(mut, nama);
                mid_count += 1;
            };
        }
        
        else if (opt == 4 ) {
            if(mid_count > 0){
                string nama;
                cout << "Insert player name :";
                cin >> nama;
                DeleteMidfielder(mut, nama);
                mid_count -= 1;
            }
            else {
                
                cout << "Data empty" << endl;
            }
        }

        else if (opt == 5 ) {

            x = defender_count;
            for (int i = 1; i <= (defender_max - x); i++) {
                string nama;
                cout << "[" << i << "] Insert player name :";
                cin >> nama;
                AddDefender(mut, nama);
                defender_count += 1;
            };
        }

        else if (opt == 6 ) {
            if(defender_count > 0){
                string nama;
                cout << "Insert player name :";
                cin >> nama;
                DeleteDefender(mut, nama);
                defender_count -= 1;
            }
            else{
                cout << "Data empty";
            }

        }
        else if (opt == 7 ) {
            string pos;
            cout << "Change player name :";
            cin >> pos;

            string nama; 
            cout << "Insert player name :";
            cin >> nama;
            SubStriker(mut, pos, nama);
        }

        else if (opt == 8 ) {
            string pos;
            cout << "Change player name :";
            cin >> pos;
            string nama; 
            cout << "Insert player name :";
            cin >> nama;
            SubMidfielder(mut, pos, nama);
        }

        else if (opt == 9 ) {
            string pos;
            cout << "Change player name :";
            cin >> pos;
            string nama; 
            cout << "Insert player name :";
            cin >> nama;
            SubDefender(mut, pos, nama);
        }
        
        else if (opt == 10) {
            showStriker(mut);
            cout << endl;

        }
        else if (opt == 11) {

            showMidfielder(mut);
            cout << endl;

        }
        else if (opt == 12) {

            showDefender(mut);
            cout << endl;

        }
        else if (opt == 13) {

            ShowAll(mut);
            cout << endl;

        }
        else if (opt == 14) {
            DelAllLine(mut);
        }
        else if (opt == 15) {
            string name;
            cout << "Enter the name you want to search : ";
            cin >> name;
            search_player(mut, name);
        }
        else if (opt == 16) {

            // delete mut child
            DelAllLine(mut);

            break;
        }
        
        else if (opt == 17) {
            exit(EXIT_SUCCESS);
        };

    };
}

int main(){


    while (true) {

        // step 1
        showMenu();
        int opt;
        cin >> opt;

        // create
        list *mut;
        mut = new list;

        // create
        CreateNewList(mut);

        if (opt == 1) {
            step1(mut, 3, 4, 3);            

        }
        else if (opt == 2) {
            step1(mut, 3, 4, 3);

        }
        else if (opt == 3) {
            step1(mut, 3, 5, 2);

        }
        else if (opt == 4) {
            step1(mut, 4, 3, 3);

        }
        else if (opt == 5) {
            step1(mut, 4, 2, 4);

        }
        else if (opt == 6) {
            step1(mut, 4, 5, 1);
        
        }
        else if (opt == 7) {
            step1(mut, 5, 3, 2);
            
        }
        else if (opt == 8) {

            break;
        };
    };
    

    return 0;
}