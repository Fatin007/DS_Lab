#include<bits/stdc++.h>
using namespace std;

float operation(float a,float b,char op){
   if(op=='+') return b+a;
   else if(op=='-') return b-a;
   else if(op=='*') return b*a;
   else if(op=='/') return b/a;
   else if(op=='^') return pow(b,a);
}

float postfixEval(string postfix){
    int a,b;
    stack<float>st;
    for(auto ch:postfix){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(operation(a,b,ch));
        }
        else st.push(ch-'0');
    }
    return st.top();
}

main(){
   string post="653-/215+*+";
   cout<<"The result is: "<<postfixEval(post);
}