#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct book
{
    double price;
    string name;
};
bool compare(book a, book b) // set the rule for sorting
{
    return (a.price < b.price || (a.price == b.price && a.name < b.name));
}
int main()
{
    int *n = new int;
    int i;
    cin >> *n;
    book a[*n]; // create a dynamic array
    for (i = 0; i < *n; i++)
    {
        cin.get();  //to miss the Enter
        getline(cin, a[i].name);
        cin >> a[i].price;
    }
    sort(a,a+*n,compare);   // quick sort
    for (i = 0; i < *n; i++)
        cout << a[i].price << ", " << a[i].name << endl;
    return 0;
}