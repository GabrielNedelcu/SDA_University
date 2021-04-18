#include <bits/stdc++.h>
using namespace std;

map<string, float> gProductPrices;

struct Product {
    string productName;
    int quantity;
};

class Client {
public:
    string clientName;
    vector<Product> shoppingCart;

    Client(string pName, vector<Product> pShoppingCart) {
        clientName = pName;
        shoppingCart=pShoppingCart;
    }

    float getShoppingCartValue() {
        float totalSum = 0;
        vector<Product>:: iterator it;
        for (it = shoppingCart.begin(); it != shoppingCart.end(); it++)
            totalSum += gProductPrices.find(it->productName)->second * it->quantity;

        return totalSum;
    }

    int getProductQuantity() {
        int numberOfProducts = 0;
        vector<Product>:: iterator it;
        for (it = shoppingCart.begin(); it != shoppingCart.end(); it++)
            numberOfProducts += it->quantity;

        return numberOfProducts;
    }

    void printClient(bool firstRule, bool secondRule) {
        if (firstRule == true && secondRule == true) {
            cout<<clientName<<": ";
            vector<Product>:: iterator it;
            for (it = shoppingCart.begin(); it != shoppingCart.end(); it++) {
                if (it!=shoppingCart.begin())
                    cout<<", "<<it->productName;
                if (it==shoppingCart.begin()) {
                    cout<<it->productName;
                }
            }
            cout<<" - "<<fixed<<setprecision(2)<<getShoppingCartValue()<<" RON"<<endl;
        }
        else {
            if(firstRule == false) {
                cout<<"Clientul "<<clientName<<"acceptat din nou."<<endl;
            }
            else if(secondRule == false) {
                cout<<"Clientul "<<clientName<<"rejectat."<<endl;
            }
        }

    }

};

int fromStringToInt(string number){
    stringstream ss(number);
    int intNUmber = 0;
    ss>>intNUmber;

    return intNUmber;
}

Client readAClient(string clientInfo) {
    string tmpName;
    string tmpVal;
    vector<Product> tmpShoppingCart;

    istringstream ss(clientInfo);

    while (ss>>tmpVal) {
        if (!isdigit(tmpVal.at(0))) { // the value read is a name
            tmpName += tmpVal + " ";
        }
        else { // the value read is a product
            string tmpProductQuantity;
            string tmpPrductName;
            Product tmpProduct;

            istringstream ss2(tmpVal);

            getline(ss2, tmpProductQuantity, 'x');
            getline(ss2, tmpPrductName);

            tmpProduct.productName = tmpPrductName;
            tmpProduct.quantity = fromStringToInt(tmpProductQuantity);

            tmpShoppingCart.push_back(tmpProduct);
        }

    }

    Client client(tmpName, tmpShoppingCart);

    return client;
}

void readAllClients(queue<Client>& clients, int numberOfClients) {
    string line;

    for (int i = 0; i < numberOfClients; i++) {
        getline(cin, line);
        clients.push(readAClient(line));
    }

}

void readProductPrices(){
    string line;
    string tmpProductName;
    float tmpProductPrice;

    while(getline(cin, line)) {
        istringstream ss(line);
        ss>>tmpProductName>>tmpProductPrice;

        gProductPrices.insert(pair<string, float>(tmpProductName, tmpProductPrice));
    }

}

bool checkFirstRule(Client& myClient) {
    bool checked = true;
    vector<Product>:: iterator it;
    for (it = myClient.shoppingCart.begin(); it != myClient.shoppingCart.end(); it++) {
        if (it->quantity > 3) {
            it->quantity = 3;
            checked=false;
        }
    }
    return checked;
}

bool checkSecondRule(Client& myClient) {
    if (myClient.getShoppingCartValue() > 100) {
        if (myClient.getProductQuantity() / myClient.getShoppingCartValue() * 100 < 10){
            return false;
        }
    }

    return true;
}


int main() {
    int n;
    queue<Client> myClients;

    cin>>n;
    cin.get();

    readAllClients(myClients, n);

    readProductPrices();

    while (!myClients.empty()) {
        bool firstRule;
        bool secondRule;

        firstRule = checkFirstRule(myClients.front());
        secondRule = checkSecondRule(myClients.front());

        myClients.front().printClient(firstRule, secondRule);

        if (firstRule == true && secondRule == true) {
            myClients.pop();
        }
        else if (firstRule == false) {
            Client copyOfTheClient(myClients.front().clientName, myClients.front().shoppingCart);
            myClients.pop();
            myClients.push(copyOfTheClient);
        }

        else if (secondRule == false) {
            myClients.pop();
        }
    }


    return 0;
}
