/*
Задание 1. Телефонный справочник
Что нужно сделать
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным номерам могут иметь одинаковые фамилии. 
В таком случае на запрос 3 необходимо выдать все номера через пробелы.
Операции запросов должны работать за O(logn) или O(logn ? количество номеров с этой фамилией).

Чек-лист для проверки задачи
• Программа корректно выводит фамилии и списки номеров.
• Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.

Как отправить задание на проверку
Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    map<string,string> telephone_book;

    
    cout << "Введите запрос:" << endl;
    string request;
    getline(cin, request);

    while (request != "stop"){

        if (request[0] >='0' && request[0] <='9'){
            if (request[request.size()-1] >= '0' && request[request.size()-1] <='9'){
                if (telephone_book.count(request))
                    cout << telephone_book[request] << endl;
                else {
                    cout << "В справочнике нет такого номера" << endl;
                }
            }
            else {
                string number = "", surname = "";
                int index = 0;
                while (request[index] != ' '){
                    number += request[index];
                    ++index;
                }
                surname = request.substr(index+1);
                telephone_book.insert(pair<string,string>(number,surname));
                cout << "Номер и фамилия добавлены" << endl;
            }
        }
        else {
            vector<string> find_surnames;
            for (map<string,string>::iterator it = telephone_book.begin(); it != telephone_book.end(); ++it){
                if (it->second == request){
                    find_surnames.push_back(it->first);
                }
            }
            if (find_surnames.size() == 0){
                cout << "В справочнике нет такой фамилии" << endl;
            }
            else {
                for (int i=0; i<find_surnames.size(); ++i){
                    cout << find_surnames[i] << endl;
                }
            }
        }
    cout << "Введите запрос (или \"stop\" для выхода):" << endl;
    getline(cin, request);

    }
}