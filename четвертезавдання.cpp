#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class goods{
private:
    string name;
    int cost;
    int count;
public:
    goods();
    goods(string name, int cost, int count);
    goods(const goods& other);
    void input();
    void output();
    string GetName() {
        return name;
    }
    int GetCost() {
        return cost;
    }
    int GetCount() {
        return count;
    }
    friend ostream& operator <<(ostream& out, goods& goods) {
        out << "Name of goods: " << goods.name << "\n";
        out << "Cost: " << goods.cost << "\n";
        out << "Coins: " << goods.count << "\n";
        return out;
    }

};
goods::goods() {
    name = "none";
    cost = 0;
    count = 0;
}
goods::goods(string name, int cost, int count) {
    this->name = name;
    this->cost = cost;
    this->count = count;
}
goods::goods(const goods& other) {
    this->name = other.name;
    this->cost = other.cost;
    this->count = other.count;
}
void goods::input() {
    cout << "Enter name of goods: \0";
    cin >> name;
    cout << "Enter cost(grivna): \0";
    cin >> cost;
    cout << "Enter count: \0";
    cin >> count;
    cout << "\n";
}
void goods::output() {
    cout << "Name of goods: " << name << "\n";
    cout << "Cost: " << cost << "\n";
    cout << "Coins: " << count << "\n";
    cout << "\n";
}
bool Compare(goods c1, goods c2) {
    return c1.GetCost() < c2.GetCost();
}
bool Sort(goods c1, goods c2) {
    return c1.GetName() < c2.GetName();
}
bool Count(goods c1, goods c2) {
    return c1.GetCount() < c2.GetCount();
}
int main() {
    int count; cout << "Enter count: \0"; cin >> count;
    goods* list = new goods[count];
    for (int i = 0; i < count; i++) {
        list[i].input();
    }
 
    for (int i = 0; i < count; i++){
        cout << list[i].GetName() << "\n";
    }
    int i = 0;
    string NameOfTheHighestGood;
    string MostPopular = list[0].GetName();
    for (int i = 0; i < count; i++){
        if (list[i].GetName() > MostPopular){
            MostPopular = list[i].GetName();
            NameOfTheHighestGood = list[i].GetCount();
        }
    }
    cout << "The most popular: " << MostPopular << "\n\n\n";
    sort(list, list + count, Count);
    cout << "List after sort popularity \n";
    for (int i = 0; i < count; i++){
        if (list[i].GetCount() >= list[0].GetCount()) {
            cout << list[i].GetName() << "\n";
        }
    }
    cout << "The least popular: " << list[0].GetName() << "\n\n";
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += list[i].GetCost()*list[i].GetCount();
    }
    cout << "Sum:" << sum << "\n\n";
    system("pause");
    return 0;
}
