#include <iostream>

using namespace std;
struct elemt{ int info;
            elemt *suiv;
            };
struct file{ elemt *first,*last;
            };
bool si_vide(file *f)
{   bool out=false;
    if (f==NULL)
        out=true;
    else{
        if((f->first==NULL)&&(f->last==NULL))
            out=true;
    }
    return out;
}
int long_file(file *f)
{  elemt *e=NULL;
   int nbe=0;
   if(si_vide(f)==false)
   { e=f->first;
   while(e!=NULL)
   {
       nbe++;
       e=e->suiv;
   }
    }
    return nbe;
}
void emfiler(file *&f,int val)
{ elemt *nov;
  if(f==NULL)
  {
      f= new file;
      f->first=NULL;
      f->last=NULL;
  }
  nov=new elemt;
  nov->info=val;
  nov->suiv=NULL;
  if(f->first==NULL)
    f->first=nov;
  else
    f->last->suiv=nov;
  f->last=nov;

}
void defiler(file *&f)
{  elemt *p;
    if(si_vide(f)==false)
      {p=f->first;
       f->first=f->first->suiv;
       delete p;
       if(f->first==NULL)
         f->last=NULL;
      }

}
int val_tete(file *f)
{
    if(si_vide(f)==false)
        return f->first->info;
    else
        return -1;
}
 void cree_file(file *&f,int tai)
 {  int valeur;
     for(int i=0;i<tai;i++)
     { cout<<"donner la valeur de "<<i+1<<" element:";
       cin>>valeur;
       emfiler(f,valeur);
     }
 }
void supprimer(file *&f)
{ if(si_vide(f))
     cout<<"la file est vide!!!!\n";
  else{
    while(f->first!=NULL)
       defiler(f);
    cout<<"la file a ete supprimer!!!!\n";
    }
}
void affich_file(file *f)
{   cout<<"-------------AFFICHAGE-------------------\n";
    if(si_vide(f)==false)
    {
        elemt *e;
        e=f->first;
        while(e!=NULL)
        {   cout<<e->info<<endl;
            e=e->suiv;
        }
    }
    else
        cout<<"la file est vide,rien a affiche!!!!!\n";
    cout<<"----------------------------------------\n";
}

int main()
{
    file *f=NULL;
    int tai;int choix;
    cout<<"donner le nombre des elements de la file:\n";
    cin>>tai;
    cree_file(f,tai);
    cout<<"|--------------------MENU------------------------|\n";
    cout<<"|1.savoir si la file est vide.                   |\n";
    cout<<"|2.la longueur de la file.                       |\n";
    cout<<"|3.emfiler un element.                           |\n";
    cout<<"|4.defiler un element.                           |\n";
    cout<<"|5.supprimer une file.                           |\n";
    cout<<"|6.affichage des elements de la file.            |\n";
    cout<<"|7.Quiter.                                       |\n";
    cout<<"|------------------------------------------------|\n";
    do{
    cout<<"donner votre choix:\n";
    cin>>choix;
    switch(choix)
    {
        case 1:{
            if(si_vide(f))
                cout<<"la file est vide!!!!\n";
            else
                cout<<"la file n est pas vide!!!!\n";
            };break;
        case 2:{
            cout<<"--------------------------------\n";
            cout<<"la longueur de la file est:"<<long_file(f)<<endl;
            cout<<"--------------------------------\n";
                };break;
        case 3:{
            int valeur;
            cout<<"donner la valeur a emfiler:\n";
            cin>>valeur;
            emfiler(f,valeur);
                };break;
        case 4:{defiler(f);
                cout<<"--------------------------------\n";
                cout<<"l element a ete defiler!!!!!\n";
                cout<<"--------------------------------\n";
                };break;
        case 5:supprimer(f);break;
        case 6:affich_file(f);break;
        case 7:{supprimer(f);
               cout<<"fin de programme a bientot\n";
                }break;
    }
    }while(choix!=7);


    return 0;
}
