#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

bool isOperator(string c){
    if(c=="+" || c=="-" || c=="/" || c=="*" || c=="^"){
        return true;
    }
    else{
        return false;
    }
}

void evaluatePrefix(string exp[],int n){

    //stack<double>temp;
        stack<double>temp;
    for(int i=n-1;i>=0;i--){
        if(!isOperator(exp[i])){
            double d=stod(exp[i]);
            temp.push(d);
        }
        else{
            if(temp.empty()){
                cout<<"The Given Expression is not CORRECT"<<endl;
                return;
            }

            double x= temp.top();
           // int x= temp.top();
            temp.pop();

            if(temp.empty()){
                cout<<"The Given Expression is not CORRECT"<<endl;
                return;
            }

            double y= temp.top();
            //int y= temp.top();
            temp.pop();

            if(exp[i]=="+"){
                temp.push(x+y);
            }
            else if(exp[i]=="-"){
                temp.push(x-y);
            }
            else if(exp[i]=="*"){
                temp.push(x*y);
            }
            else if(exp[i]=="/"){
                temp.push(x/y);
            }
            else if(exp[i]=="^"){
                temp.push(pow(x,y));
            }
        }
    }

    //double result=temp.top();
    double result=temp.top();
    temp.pop();

    if(!temp.empty()){
        cout<<"The Given Expression is not CORRECT"<<endl;
        return;
    }
    cout<<"Result: "<<result<<endl;

}



int main(){




    stack<string> exp;
    string s;
    cout<<"enter 'stop' to stop taking input"<<endl;

    while (true){

        cin>>s;
        if(s=="stop"){break;}
        exp.push(s);
    }

    int sz=exp.size();

    string expression[sz];


    for(int i=sz-1;i>=0; i--){
        expression[i]= exp.top();
        exp.pop();
    }


    /*for(int i=0;i<sz;i++){
        cout<<expression[i]<<" ";
    }*/
    evaluatePrefix(expression,sz);




}
