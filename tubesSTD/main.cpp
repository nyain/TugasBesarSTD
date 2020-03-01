#include "list.h"

int main() {
    int choice = 0;
    string name, mata, dosen, kelas;
    List1 nama;
    List2 matkul;
    ListBase Base;
    connect R;
    createListParent(nama);
    createListChild(matkul);
    createListBase(Base);
    cout << "Selamat Datang di Mesin Otomatis!!" << endl;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. insert list nama"<<endl;
        cout<<"2. insert list mata kuliah"<<endl;
        cout<<"3. insert data mahasiswa yang mengambil mata kuliah dan nilainya"<<endl;
        cout<<"4. delete nama mahasiswa"<<endl;
        cout<<"5. delete mata kuliah"<<endl;
        cout<<"6. delete data mahasiswa dengan mata kuliah"<<endl;
        cout<<"7. print list mahasiswa"<<endl;
        cout<<"8. print list mata kuliah"<<endl;
        cout<<"9. print semua data mahasiswa dengan mata kuliah dan nilai"<<endl;
        cout<<"10. mencari median matkul"<<endl;
        cout<<"11. mencari rata-rata nilai matkul"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"input choice: ";
        cin >> choice;
        switch(choice) {
        case 1:
            cleared();
            cout << "Masukkan nama : ";
            cin.get();
            getline(cin, name);
            cout << "Masukkan kelas anda : ";
            getline(cin, kelas);
            if (findElmParent(nama, name) == NULL) {
                insertListParent(nama, CreateElmParent(name, kelas));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, mata kuliah sudah terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";            
            }
            cin.get();
            break;
        case 2:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin.get();
            getline(cin, mata);
            cout << "Masukkan dosen anda : ";
            getline(cin, dosen);
            if (findElmChild(matkul, mata) == NULL) {
                insertListChild(matkul, CreateElmChild(mata, dosen));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, mata kuliah sudah terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";            
            }
            cin.get();
            break;
        case 3:
            cleared();
            cout << "Masukkan nama anda : ";
            cin >> name;
            cout << "Anda mengambil mata kuliah : ";
            cin >> mata;
            if (findElmParent(nama, name) != NULL && findElmChild(matkul, mata) != NULL && findElmBaseAll(Base, findElmParent(nama, name), findElmChild(matkul, mata)) == NULL) {
                insertBase(Base, CreateElmBase(findElmParent(nama, name), findElmChild(matkul, mata)));
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, anda tidak terdaftar dalam mahasiswa atau mata kuliah tidak terdaftar\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 4:
            cleared();
            cout << "Masukkan nama : ";
            cin >> name;
            if (findElmParent(nama, name) != NULL) {
                deleteListParent(nama, name);
                if (findElmBasebyName(Base, name) != NULL) {
                    deleteBasebyName(Base, findElmBasebyName(Base, name));
                }
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 5:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin >> mata;
            if (findElmChild(matkul, mata) != NULL) {
                deleteListChild(matkul, mata);
                if (findElmBasebyCourse(Base, mata) != NULL) {
                    deleteBasebyName(Base, findElmBasebyCourse(Base, mata));
                }
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 6:
            cleared();
            cout << "Masukkan nama : ";
            cin >> name;
            cout << "Masukkan mata kuliah : ";
            cin >> mata;
            R = findElmBaseAll(Base, findElmParent(nama, name), findElmChild(matkul, mata));
            if (R != NULL) {
                deleteBasebyName(Base, R);
                cout << "Program Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Maaf, nama tidak ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 7:
            cleared();
            printInfoParent(nama);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 8:
            cleared();
            printInfoChild(matkul);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 9:
            cleared();
            printInfoBase(Base);
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
            cin.get();
            break;
        case 10:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin >> mata;
            if (findElmBasebyCourse(Base, mata) != NULL) {
                cout << nilaiMedianMatkul(Base, mata);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 11:
            cleared();
            cout << "Masukkan mata kuliah : ";
            cin >> mata;
            if (findElmBasebyCourse(Base, mata) != NULL) {
                cout << nilaiRerata(Base, mata);
                cout << "\n\nProgram Run Success! [Press Enter to Continue]. . .";
            } else {
                cout << "Mata Kuliah Tidak Ditemukan\n\n" << "Program Run Success! [Press Enter to Continue]. . .";
            }
            cin.get();
            cin.get();
            break;
        case 12:
            cleared();
            printInfoParent(nama);
            printInfoChild(matkul);
            printInfoBase(Base);
            cin.get();
            cout << "Program Run Success! [Press Enter to Continue]. . .";
            cin.get();
        }
        if (choice == 0) {
            break;
        }
    } while (true);
}