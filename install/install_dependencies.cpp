#include <iostream>
using namespace std;
int main(){
system("clear");
cout << "Please keep your Internet Turned On " << endl;
cout << "Have you turned On ? (Yes/No) " << endl;
string a;
cin >> a;
if (a == "Yes" || a == "yes" || a == "y" || a == "Y" || a == "YES"){
system("chmod +x start");
system("./start");
}
else {
    if (a == "No" || a == "NO" || a == "N" || a == "n" || a == "no"){
    system("exit");
    cout << "Please try again later when network is available\n";
    }
}
return 0;

}

