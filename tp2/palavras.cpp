#include<iostream>

int main(){
    std::string a;
    std::cin >> a;
    char vogais[5]={'a','e','i','o','u'};

    for (int i = 0; i < 5; i++){
        int count = 0; 
        for (std::string::iterator it = a.begin(); it != a.end(); it++){
            if (*it == vogais[i]){
                count++;
            }
        }
       if (count != 0){
            std::cout << vogais[i] << " " << count << std::endl;
       }
    }

    return 0;
}