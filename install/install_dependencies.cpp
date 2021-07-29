#include <iostream>
using namespace std;
int main(){
system("clear");
cout << "Please keep your Internet Turned On " << endl;
cout << "Have you turned On ? (Yes/No) " << endl;
string a;
cin >> a;
//if(checkformodification("start", "10a72e2e389ab6d338e417d87dcaa67f9bb804ff40e9ba7ccf120a2dc0bb6820") && checkformodification("install_dependencies.cpp", "185e1ec2fcb6d36b9a44571b3fa0fb354c430fbf631a015b46d411ca7c3dedb4") && checkformodification("../random/csprng.cpp", "8b409deb0f2e086d00c99d2765dd56713bb33d16c675d12fe5c6903c35d50989") && checkformodification("../random/csprng.h", "c3e5389b011088b5e5ab6c68c08cc3b952215bd52c7a28968b74c993d626afe2") && checkformodification("../random/csprng.hpp", "1cb15d8415a63fce15cc85ddcd15666973e2fb41c4edfbd3b11503ced6ba589e") && checkformodification("../random/is_iterable.hpp", "4ab295afd50988c2562d89362ae7deaf91653c5d997258525396e61bf7cc96e5") && checkformodification("../hash/sha3.cpp", "8c070dbc66dee46ce8340a6c83264c922199e51ebabbc675ea0bb08301bab7fa") &&  checkformodification("../hash/sha3.h", "302478a22134b2eb1a598cd48d331fe80c4233d3dbe90a8508ff200477e73503")){ 
if (a == "Yes" || a == "yes" || a == "y" || a == "Y" || a == "YES"){
system("chmod +x start");
system("./start");
}
else {
    if (a == "No" || a == "NO" || a == "N" || a == "n" || a == "no"){
    system("exit");
    cout << "Please try again later when network is available\n";
    }
//}
}
return 0;

}

