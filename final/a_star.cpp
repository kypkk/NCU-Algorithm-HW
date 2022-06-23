#include <iostream>

using namespace std;

void sol();



int main(){

    int datas;
    cin >> datas;
    while(datas--){
        sol();
    }

    return 0;

}

void sol(){
    // getting input
    int S[3];
    int A[3];
    int B[3];
    int C[3];
    int D[3];
    int E[3];
    int F[3];
    int G;
    int H;
    int I;
    int target_stage;
    cin >> S[0] >> S[1] >> S[2];
    cin >> A[0] >> A[1] >> A[2];
    cin >> B[0] >> B[1] >> B[2];
    cin >> C[0] >> C[1] >> C[2];
    cin >> D[0] >> D[1] >> D[2];
    cin >> E[0] >> E[1] >> E[2];
    cin >> F[0] >> F[1] >> F[2];
    cin >> G >> H >> I;
    cin >> target_stage;
    
    // F, G, H of all the point
    int F_s, F_a, F_b, F_c, F_d, F_e, F_f, F_g, F_h, F_i, F_target;
    int G_s = 0;
    int G_a = S[0];
    int G_b = S[1]; 
    int G_c = S[2]; 
    int G_d = 100000; 
    int G_e = 100000; 
    int G_f = 100000; 
    int G_g = 100000; 
    int G_h = 100000; 
    int G_i = 100000; 
    int G_target = 100000; 

    int H_s = 100000;
    int H_a = 100000;
    int H_b = 100000; 
    int H_c = 100000; 
    int H_d = 100000; 
    int H_e = 100000; 
    int H_f = 100000; 
    int H_g = 100000; 
    int H_h = 100000; 
    int H_i = 100000; 
    int H_target = 0; 

    // calculate F(S)
    for(int i = 0; i < 3; i++){
        if(S[i] < H_s){
            H_s = S[i];
        }
    }
    F_s = H_s + G_s;
    
    // F(A)    
    for(int i = 0; i < 3; i++){
        if(A[i] < H_a){
            H_a = A[i];
        }
    }
    F_a = G_a + H_a;

    // F(B)    
    for(int i = 0; i < 3; i++){
        if(B[i] < H_b){
            H_b = B[i];
        }
    }
    F_b = G_b + H_b;

    // F(C)
    for(int i = 0; i < 3; i++){
        if(C[i] < H_c){
            H_c = C[i];
        }
    }
    F_c = G_c + H_c;

    // F(D)
    for(int i = 0; i < 3; i++){
        if(D[i] < H_d){
            H_d = D[i];
        }
    }
    if(G_a + A[0] < G_d)
        G_d = G_a + A[0];
    if(G_b + B[0] < G_d)
        G_d = G_b + B[0];
    if(G_c + C[0] < G_d)
        G_d = G_c + C[0];
    F_d = G_d + H_d; 

    // F(E)
    for(int i = 0; i < 3; i++){
        if(E[i] < H_e){
            H_e = E[i];
        }
    }
    if(G_a + A[1] < G_e)
        G_e = G_a + A[1];
    if(G_b + B[1] < G_e)
        G_e = G_b + B[1];
    if(G_c + C[1] < G_e)
        G_e = G_c + C[1];
    F_e = G_e + H_e;

    // F(F)
    for(int i = 0; i < 3; i++){
        if(F[i] < H_f){
            H_f = F[i];
        }
    }
    if(G_a + A[2] < G_f)
        G_f = G_a + A[2];
    if(G_b + B[2] < G_f)
        G_f = G_b + B[2];
    if(G_c + C[2] < G_f)
        G_f = G_c + C[2];
    F_f = G_f + H_f;

    // F(G)
    H_g = G;
    if(G_d + D[0] < G_g)
        G_g = G_d + D[0];
    if(G_e + E[0] < G_g)
        G_g = G_e + E[0];
    if(G_f + F[0] < G_g)
        G_g = G_g + F[0];
    F_g = G_g + H_g; 
    
    // F(H)
    H_h = H;
    if(G_d + D[1] < G_h)
        G_h = G_d + D[1];
    if(G_e + E[1] < G_h)
        G_h = G_e + E[1];
    if(G_f + F[1] < G_h)
        G_h = G_f + F[1];
    F_h = G_h + H_h; 

    // F(I)
    H_i = I;
    if(G_d + D[2] < G_i)
        G_i = G_d + D[2];
    if(G_e + E[2] < G_i)
        G_i = G_e + E[2];
    if(G_f + F[2] < G_i)
        G_i = G_f + F[2];
    F_i = G_i + H_i;

    // F(T)
    if(F_g < G_target)
        G_target = F_g;
    if(F_h < G_target)
        G_target = F_h;
    if(F_i < G_target)
        G_target = F_i;
    F_target = G_target + H_target;
    
    // cases for targetlevel
    int answer_2 = 100000;
    int answer_3 = 100000;
    int answer_4 = 100000;
    switch(target_stage){
        case 1:
            cout << F_s << endl;
            break;
        case 2:
            
            if(F_a < answer_2)
                answer_2 = F_a;
            if(F_b < answer_2)
                answer_2 = F_b;
            if(F_c < answer_2)
                answer_2 = F_c;
            cout << answer_2 << endl;
            break;
        case 3:
            
            if(F_d < answer_3)
                answer_3 = F_d;
            if(F_e < answer_3)
                answer_3 = F_e;
            if(F_f < answer_3)
                answer_3 = F_f;
            cout << answer_3 << endl;
            break;
        case 4:
            
            if(F_g < answer_4)
                answer_4 = F_g;
            if(F_h < answer_4)
                answer_4 = F_h;
            if(F_i < answer_4)
                answer_4 = F_i;
            cout << answer_4 << endl;
            break;
        case 5:
            cout << F_target << endl;
            break;            
    }
}