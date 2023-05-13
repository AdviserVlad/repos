// ОБЯЗАТЕЛЬНО ЗАПУСКАЙТЕ В С++17 ИЗ-ЗА FILESYSTEM.
#include <iostream>
#include <fstream>
#include <string>   
#include <filesystem> 
#include <vector>
#include <stdio.h>
using namespace std;
namespace fs = filesystem;

struct MusicCard {
    string MusicName;
    string AuthorName;
    string DATE = NULL;
    string FileName;
};

vector<MusicCard> MusicInFolder(string FolderName) {
    vector <MusicCard> a;
    string path = FolderName + "/";
    for (auto& p : fs::directory_iterator(path)) {
        string NOF = p.path().string();
        ifstream fin(NOF, ios_base::in);
        string name;
        getline(fin, name);
        string Author;
        getline(fin, Author);
        string Date;
        getline(fin, Date);
        fin.close();
        a.push_back({ name, Author, Date, NOF });
    }
    return a;
}

void MusicText(vector<MusicCard> List) {
    system("cls");
    cout << "Выберите музыкальное произведение: " << endl;
    for (int i = 0; i < List.size(); i++) {
        cout << i + 1 << " - " << List[i].MusicName << endl;
    }
    int a; cin >> a;
    while ((a <= 0) || (a > List.size())) {
        cout << "Неверное значение." << endl;
        cin >> a;
    }
    ifstream fin(List[a - 1].FileName, ios_base::in);
    int count = 0; string str;
    while (getline(fin, str)) {
        if (count >= 3) cout << str << endl;
        else count++;
    }
    _getwch();
}

void SaveMusic(vector<MusicCard> List) {
    system("cls");
    cout << "Введите название: ";
    string name; getline(cin, name);
    cout << "Введите автора: ";
    string author; getline(cin, author);
    cout << "Введите год (- если не известен): ";
    string year; cin >> year;
    if (year == "-") { year = ""; }
    string NOF = "List/" + name + ".txt";
    List.push_back({ name, author, year, NOF });
    string str; size_t n = List.size() - 1;
    ofstream fout(List[n].FileName, ios_base::out);
    fout << List[n].MusicName << endl << List[n].AuthorName << endl << List[n].DATE;
    cout << "Чтобы закончить ввод, введите строку \'(+)-?*/\'." << endl;
    getline(cin, str);
    while (str != "(+)-?*/") {
        fout << str << endl;
        getline(cin, str);
    }
    fout.close();
}

vector<MusicCard> DeleteMusic(vector<MusicCard> List) {
    system("cls");
    cout << "Выберите музыкальное произведение: " << endl;
    for (int i = 0; i < List.size(); i++) {
        cout << i + 1 << " - " << List[i].MusicName << endl;
    }
    int a; cin >> a;
    while ((a <= 0) || (a > List.size())) {
        cout << "Неверное значение." << endl;
        cin >> a;
    }
    remove(List[a - 1].FileName.c_str());
    List.pop_back();
    return List;
}

void FindAuthorMusic(vector<MusicCard> List) {
    system("cls");
    cout << "Введите имя автора: "; int count = 1;
    string name; getline(cin, name);
    for (int i = 0; i < List.size(); i++) {
        ifstream fin(List[i].FileName, ios_base::in);
        string str;
        getline(fin, str);
        getline(fin, str);
        if (str == name) { cout << count << " - " << List[i].MusicName << endl; count++; }
    }
    if (count == 1) { cout << "Музыка этого автора не найдена."; }
    _getwch();
}

void FindWordInMusic(vector<MusicCard> List) {
    system("cls");
    cout << "Введите слово для поиска: ";
    string target; cin >> target; int count = 1;
    for (int i = 0; i < List.size(); i++) {
        ifstream fin(List[i].FileName, ios_base::in);
        string str;
        while (fin >> str) {
            if (str == target) {
                cout << count << " - " << List[i].MusicName << endl; count++;
                break;
            }
        }
        fin.close();
    }
    if (count == 1) { cout << "Слово не найдено."; }
    _getwch();
}

vector<string> FiletoSplit(string FilePath) {
    vector <string> Split;
    fstream fin(FilePath, ios_base::in);
    string str;
    while (getline(fin, str)) Split.push_back(str);
    fin.close();
    return Split;
}

void EditSong(vector<MusicCard> List) {
    system("cls");
    cout << "Выберите музыкальное произведение: " << endl;
    for (int i = 0; i < List.size(); i++) {
        cout << i + 1 << " - " << List[i].MusicName << endl;
    }
    int a; cin >> a;
    while ((a <= 0) || (a > List.size())) {
        cout << "Неверное значение." << endl;
        cin >> a;
    }
    a = a - 1;
    while (a != -1) {
        system("cls");
        ifstream f(List[a].FileName, ios_base::in);
        cout << "Музыка: " << List[a].MusicName << "; Автор: " << List[a].AuthorName << endl;
        string str; int count = 1;
        while (getline(f, str)) {
            if (count > 3) { cout << count << " | " << str << endl; }
            count++;
        }
        f.close();
        cout << "----------------" << endl << "Выберите номер строки: ";
        int b; cin >> b; cin.get();
        if ((b <= 3) || (b >= count)) {
            break;
        }
        b = b - 1;
        cout << "Введите строку: ";
        string x; cin >> x;
        vector <string> Split = FiletoSplit(List[a].FileName);
        ofstream fout(List[a].FileName, ios_base::trunc);
        for (int i = 0; i < b; i++) fout << Split[i] << endl;
        fout << x << endl;
        for (int i = b + 1; i < Split.size(); i++) fout << Split[i] << endl;
        fout.close();
    }
}

void main_menu() {
    string x;
    cout << "Введите имя папки с текстами: ";
    getline(cin, x);
    system("cls"); int a = 1;
    while (a != 0) {
        system("cls");
        cout << "Каталог текстов песен" << endl;
        cout << "---------------------" << endl;
        cout << "Выберите действие: " << endl;
        cout << "[1] - Вывести текст песни." << endl;
        cout << "[2] - Сохранить текст песни в файл." << endl;
        cout << "[3] - Удалить песню из каталога." << endl;
        cout << "[4] - Поиск песен одного автора." << endl;
        cout << "[5] - Поиск слова в песнях." << endl;
        cout << "[6] - Изменение текста песни." << endl;
        cout << "[0] - Выход из программы." << endl;
        cin >> a;
        while ((a < 0) || (a > 6)) {
            cout << "Неверное значение." << endl;
            cin >> a;
        }
        cin.get();
        vector<MusicCard> List = MusicInFolder(x);
        if (a == 1) MusicText(List);
        else if (a == 2) SaveMusic(List);
        else if (a == 3) DeleteMusic(List);
        else if (a == 4) FindAuthorMusic(List);
        else if (a == 5) FindWordInMusic(List);
        else if (a == 6) EditSong(List);
        else if (a == 0) break;
    }

}

int main() {
    system("chcp 1251");
    system("cls");
    main_menu();
}