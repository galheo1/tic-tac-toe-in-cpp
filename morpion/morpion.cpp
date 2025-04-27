#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

class Morpion
{
    public:
        void affichage(){
            cout<<"\n\n";
            int i;
            int j;
	        for (i=0; i<3; i++)
	        {
	            cout<<"\n|";
	            for (j=0;j<3; j++)
	            {
	                cout<<game[i][j]<<"|";
	            }
            }
	        cout <<endl;
        };
        
        void begin()
        {
            int i,j;
	        for (i=0; i<3; i++)
	        {
	            for (j=0;j<3; j++)
	            {
	                game[i][j]=' ';
	            }
            }
        };


        void update()
        {   
            string a="1";
            while(endy[a[0]]){
                playing();
                affichage();
                a = end();
            }
            cout<<"\n\n\n";
            string gagnant= winer[a[1]];
            if (gagnant == winer['a']){
                cout<<gagnant;
            
            }
            else{
                cout<<gagnant<< " win!!"<<endl;
            };
            
        };
        
        void playing()
        {
            string play;
            cout <<  winer[player[turn%2]] << " à vous de jouer -> ";
            cin >> play;
            cout<<endl;
            bool valide = true;
            
            while(valide){
                int a = search(play);
                int b = play[1]-'0'-1;
                //cout<<a<<"  "<<b<<"  "<< search(play)<<endl;
                
                if (game[a][b]==' '){
                    game[a][b] = player[turn%2];
                    valide = false;
                }
                else{
                    cout << "case déjà prise, veuillez reccomencer -> ";
                    cin >> play;
                    cout<<endl;
                };
             };
             
            
            
            
            
            turn ++;
            
        };
        
        string end()
        {
            char a;
            int b;
            // longueure
            int i;
            int j;
            for(i=0; i<3; i++){
                if(game[i][0]!=' '){
                    a = game[i][0];
                    b = 0;
                    for(j=1; j<3; j++){
                        if (game[i][j]!=a){
                            break;
                        }
                        else{
                            b++;
                        };
                    }
                    if(b==2){
                        string c(1, a);
                        return "0"+c;
                    }
                }
            }
            
            //hauteure
            for(i=0; i<3; i++){
                if (game[0][i]!=' '){
                    a=game[0][i];
                    b = 0;
                    for(j=1; j<3; j++){
                        if (game[j][i]!=a){
                            break;
                        }
                        else{
                            b++;
                        };
                    if(b==2){
                        string c(1, a);
                        return "0"+c;
                    }
                    }
                }
            }
            
            //diagonales
            //gauche
            a = game[0][0];
            b = 0;
            for(i=0; i<3; i++){
                if(game[i][i]==a and a!=' '){
                    b++;
                }
                else{
                    break;
                };
            }
            if(b==3){
                string c(1, a);
                return "0"+c;
            };
            
            //droite
            a = game[0][0];
            b = 0;
            for(i=0; i<3; i++){
                if(game[2-i][i]==a and a!=' '){
                    b++;
                }
                else{
                    break;
                };
            }
            if(b==3){
                string c(1, a);
                return "0"+c;
            };
            
            
            
            
            
            //egalitée
            //peut jouer?
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    if(game[i][j]==' '){
                        return "1";
                    }
                }
            }
            return "0a";
        };
    private:
	    char game[3][3];
	    map<char,int> dico={
	        {'a',0},
	        {'b',1},
	        {'c',2}
	        };
	    map<int,char> player={
	        {0, 'x'},
	        {1, '0'}
	    };
	    map<char, bool> endy={
	        {'1', true},
	        {'0', false}
	    };
	    map<char, string> winer={
	        {'x', "player 1"},
	        {'0', "player 2"},
	        {'a', "equality!!"}
	    };
	    int search(string code="a1"){
	        char c = code[0];
	        return dico[c];
	    };
        int turn = 0;

};


