#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct voiture{
    char modele[50];
    char serie[50];
    char couleur[50];
    char puissance[50];
};

struct client{
     char cin[50];
     char nom[50];
     char prenom[50];

};

struct commande{
    char cin[50];
    char serie[50];
    char date[50];
};


struct liste {
    struct element *tete ;
    struct element *queu ;
};

struct element{
    struct client cle ;
    struct element *suivant ;
};

struct v_element{
    struct voiture cle ;
    struct v_element *suivant ;
};


struct v_liste {
    struct v_element *tete ;
    struct v_element *queu ;
};

struct c_element{
    struct commande cle ;
    struct c_element *suivant ;
            };

struct c_liste {
    struct c_element *tete ;
    struct c_element *queu ;
 };

void afficher_client(struct client clt){
        printf("Cin :");
        puts(clt.cin);
        printf("Nom :");
        puts(clt.nom);
        printf("Prenon :");
        puts(clt.prenom);
}

void afficher_commande(struct commande cmd){
        printf("Cin :");
        puts(cmd.cin);
        printf("Serie :");
        puts(cmd.serie);
        printf("Date :");
        puts(cmd.date);
}









void v_creer_liste(struct v_liste *ll){
      ll->tete=NULL;
      ll->queu=NULL;
}

void v_ajouter_fin(struct voiture vtr , struct v_liste *ll) {
    struct v_element *q;
    q=(struct v_element *)malloc(sizeof(struct v_element));
    q->cle=vtr ;
    q->suivant=NULL;
    if(liste_vide(*ll)){
        ll->tete=q;
        ll->queu=q;
    }
    else{
        ll->queu->suivant=q;
        ll->queu=q;
    }
}

int v_liste_vide(struct  v_liste ll){
        return (ll.queu== NULL && ll.tete== NULL);
}


struct voiture v_premier(struct v_liste ll){
            assert(!v_liste_vide(ll));
            return (ll.tete->cle);
}

void v_afficher_liste(struct v_liste ll){
    if(v_liste_vide(ll)){
        puts("aucun element dans la liste");
        return ;
}

struct v_element* p ;
    p= ll.tete ;
    int i=1;
    while(p){
    printf("_%d______________________________________\n",i);
        afficher_voiture(p->cle);
        printf("\n\n");
        p=p->suivant ;
        i++;
    }
}

 struct voiture* v_supprimer_element(char mat[50], struct v_liste *ll) {
    if(v_liste_vide(*ll))
        return NULL ;

    struct v_element *p =ll->tete;
    struct v_element *q=NULL ;
    while(p){
       //
        if(!strcmp(p->cle.serie,mat))
                break ;
        p=p->suivant;
    }
    return p ;
}

  void v_suprimer_ref(struct v_liste *ll, struct v_element *q){
    struct v_element *p,*t;
    if(v_liste_vide(*ll))
        return ;
    if(ll->tete==ll->queu && ll->tete==q)
    {

        ll->tete=NULL;
        ll->queu=NULL;
    }
    else if (q==ll->tete)
    {
                ll->tete=ll->tete->suivant;
    }
    else if(q==ll->queu)
    {

        t=ll->tete;
        while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=NULL;
        ll->queu=t;
    }
    else
    {
        t=ll->tete;
       while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=q->suivant;
    }
    free(q);
    }







void c_creer_liste(struct c_liste *ll){
           ll->tete=NULL;
           ll->queu=NULL;
            }
void c_ajouter_fin(struct commande cmd , struct c_liste *ll){
    struct c_element *q;
    q=(struct c_element *)malloc(sizeof(struct c_element));
    q->cle=cmd ;
    q->suivant=NULL;
    if(c_liste_vide(*ll)){
        ll->tete=q;
        ll->queu=q;
    }
    else{
        ll->queu->suivant=q;
        ll->queu=q;
    }
}

int c_liste_vide(struct  c_liste ll){
        return (ll.queu== NULL && ll.tete== NULL);
        }

struct commande c_premier(struct c_liste ll){
            assert(!c_liste_vide(ll));
            return (ll.tete->cle);
            }
void c_afficher_liste(struct c_liste ll){
    if(c_liste_vide(ll)){
        puts("aucun element dans la liste");
        return ;
    }
    struct c_element* p ;
    p= ll.tete ;

    int i=1;
    while(p){
    printf("_%d______________________________________\n",i);
        afficher_commande(p->cle);
        printf("\n\n");
        p=p->suivant ;
        i++;
    }
    }

 struct commande* c_supprimer_element(char cin[50], struct c_liste *ll){
    if(c_liste_vide(*ll))
        return NULL ;
   // puts("done1");
    struct c_element *p =ll->tete;
    struct c_element *q=NULL ;
    while(p){
       //     puts("done1");
        if(!strcmp(p->cle.serie,cin))
                break ;
        p=p->suivant;
    }
    return p ;
}

  void c_suprimer_ref(struct c_liste *ll, struct c_element *q){
    struct c_element *p,*t;
    if(c_liste_vide(*ll))
        return ;
    if(ll->tete==ll->queu && ll->tete==q)
    {

        ll->tete=NULL;
        ll->queu=NULL;
    }
    else if (q==ll->tete)
    {
                ll->tete=ll->tete->suivant;
    }
    else if(q==ll->queu)
    {

        t=ll->tete;
        while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=NULL;
        ll->queu=t;
    }
    else
    {
        t=ll->tete;
       while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=q->suivant;
    }
    free(q);
    }










void creer_liste(struct liste *ll){
           ll->tete=NULL;
           ll->queu=NULL;
            }
void ajouter_fin(struct client clt , struct liste *ll){
    struct element *q;
    q=(struct element *)malloc(sizeof(struct element));
    q->cle=clt ;
    q->suivant=NULL;
    if(liste_vide(*ll)){
        ll->tete=q;
        ll->queu=q;
    }
    else{
        ll->queu->suivant=q;
        ll->queu=q;
    }
}
void supprimer_premier(struct liste *ll){
        assert(!liste_vide(*ll));
        struct element *q;
        q=ll->tete;
        ll->tete=ll->tete->suivant;
        free(q);
        if(ll->tete==NULL)
            ll->queu=NULL;
}

int liste_vide(struct  liste ll){
        return (ll.queu== NULL && ll.tete== NULL);
        }
struct client  premier(struct liste ll){
            assert(!liste_vide(ll));
            return (ll.tete->cle);
            }


void afficher_liste(struct liste ll){
    if(liste_vide(ll)){
        puts("aucun element dans la liste");
        return ;
    }
    struct element* p ;
    p= ll.tete ;

    int i=1;
    while(p){
    printf("_%d______________________________________\n",i);
        afficher_client(p->cle);
        printf("\n\n");
        p=p->suivant ;
        i++;
    }
    }

    struct liste ll ;
struct v_liste lv ;
struct c_liste lc ;
struct element* supprimer_element(char cin[50], struct liste *ll){
    if(liste_vide(*ll))
        return NULL ;
   // puts("done1");
    struct element *p =ll->tete;
    struct element *q=NULL ;
    while(p){
       //     puts("done1");
        if(!strcmp(p->cle.cin,cin))
                break ;
        p=p->suivant;
    }
    return p ;
}
    void suprimer_ref(struct liste *ll, struct element *q){
    struct element *p,*t;
    if(liste_vide(*ll))
        return ;
    if(ll->tete==ll->queu && ll->tete==q)
    {

        ll->tete=NULL;
        ll->queu=NULL;
    }
    else if (q==ll->tete)
    {
                ll->tete=ll->tete->suivant;
    }
    else if(q==ll->queu)
    {

        t=ll->tete;
        while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=NULL;
        ll->queu=t;
    }
    else
    {
        t=ll->tete;
       while(t && t->suivant!=q){
                t=t->suivant;
        }
        t->suivant=q->suivant;
    }
    free(q);
    }


//



void entrer_client(struct client *clt)
{

    printf("Entrez Le Cin De La Client : ");
    scanf("%s", clt->cin);
    printf("Entrez Le Nom De La Client : ");
    scanf("%s", clt->nom);
    printf("Entrez Le Prenon De La Client : ");
    scanf("%s", clt->prenom);

}

void ajouter_client(){
    int i ;
    puts("ajouter");
    struct client clt;
    entrer_client(&clt);
    ajouter_fin(clt,&ll);
    puts("TAPER 1 Pour Ajouter Un autre Client");
    puts("TAPER 0 Retourner Au Menu Gestion Client ");
    scanf("%d",&i);
    if(i==1)
        ajouter_client();
    if(i==0){
        system("cls") ;
        menu_client();
    }
}
void modifier_client(){
    int i;
    char cin[50];
    puts("saisir le cin de client qe vous voulez le modifier :");
    scanf("%s",cin);
    puts("ce client que vous allez le modifier :");
    struct element *e = supprimer_element(cin,&ll) ;
    struct client q =e->cle ;
   //afficher_client(q);
    modifier(&e->cle);

    puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
    scanf("%d",&i);
    if(i==0)
        menu_client();


}
void supprimer_client(){
    int i ;
    puts("supprimer");
    char cin[50];
    scanf("%s",cin);
    suprimer_ref(&ll,supprimer_element(cin, &ll));
    puts("done");
    puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
    scanf("%d",&i);
    if(i==0){
        menu_client();
    }
    }
void afficher_les_clients(){
puts("liste");
int i ;
afficher_liste(ll);
puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
scanf("%d",&i);

if(i==0){
    system("cls");
    menu_client();
}
}

void entrer_voiture(struct voiture *vtr)
{

    printf("Entrez Le Modele De La Voiture : ");
    scanf("%s", vtr->modele);
    printf("Entrez Le Serie De La Voiture : ");
    scanf("%s", vtr->serie);
    printf("Entrez Le Couleur De La Voiture : ");
    scanf("%s", vtr->couleur);
    printf("Entrez Le Puissance De La Voiture : ");
    scanf("%s", vtr->puissance);

}
void afficher_voiture(struct voiture vtr){
        printf("Modele :");
        puts(vtr.modele);
        printf("Serie :");
        puts(vtr.serie);
        printf("Couleur :");
        puts(vtr.couleur);
        printf("Puissance :");
        puts(vtr.puissance);
}




void ajouter_voiture(){
    puts("ajouter");
     int i ;

    struct voiture vtr;
    entrer_voiture(&vtr);
    v_ajouter_fin(vtr,&lv);
    puts("TAPER 1 Pour Ajouter Un autre Voiture");
    puts("TAPER 0 Retourner Au Menu Gestion Voiture ");
    scanf("%d",&i);
    if(i==1)
        ajouter_voiture();
    if(i==0){
        system("cls") ;
        menu_voiture();
    }
}





void modifier_voiture(){
    puts("modifier");
      int i;
    char mat[50];
    puts("saisir le Serie de voiture qe vous voulez le modifier :");
    scanf("%s",mat);
    puts("ce voiture que vous allez le modifier :");
    struct v_element *e = v_supprimer_element(mat,&lv) ;
    struct voiture q =e->cle ;
   //afficher_client(q);
    v_modifier(&e->cle);

    puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
    scanf("%d",&i);
    if(i==0)
        menu_voiture();


}
void supprimer_voiture(){
    int i ;
    puts("supprimer");
    char mat[50];
    scanf("%s",mat);
    v_suprimer_ref(&lv,v_supprimer_element(mat, &lv));
    puts("succes");
    puts("TAPEZ 0 POUR RETOURNER AU MENU PRECEDENT");
    scanf("%d",&i);
    if(i==0){
        menu_voiture();
    }
    }
void afficher_les_voitures(){
puts("liste");

int i ;
v_afficher_liste(lv);
puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
scanf("%d",&i);

if(i==0){
    system("cls");
    menu_voiture();
}
}
//A propos commande

void entrer_commande(struct commande *cmd)
{

    printf("Entrez Le Cin De La Commande: ");
    scanf("%s", cmd->cin);
    printf("Entrez Le Serie De La Commande : ");
    scanf("%s", cmd->serie);
    printf("Entrez Le Date De La Commande : ");
    scanf("%s", cmd->date);

}

void ajouter_commande(){
int i ;

    struct commande cmd;
    entrer_commande(&cmd);
    c_ajouter_fin(cmd,&lc);
    puts("TAPER 1 Pour Ajouter Un autre Commande");
    puts("TAPER 0 Retourner Au Menu Gestion Commande ");
    scanf("%d",&i);
    if(i==1)
        ajouter_commande();
    if(i==0){
        system("cls") ;
        menu_commande();
    }
}
void afficher_les_commandes(){
    puts("liste");
    int i ;
    c_afficher_liste(lc);
    puts("TAPER 0 POUR RETOURNER AU MENU PRECEDENT");
    scanf("%d",&i);

    if(i==0){
        system("cls");
        menu_commande();
    }
}
void afficher_les_commandateurs(){
    puts("list");
}
//les menus
void menu_client(){
    int i ;
    puts("Menu Client");
    puts("1-Ajouter Un Client");
    puts("2-Modifier Un Client");
    puts("3-Supprimer Un client");
    puts("4-Afficher La Liste Des Clients");
    puts("5-Retourner AU menu");
    puts("CHOISISSZR ENTRE 1 ET 5 ");
    scanf("%d",&i);
    system("cls");
    if(i==1){
        ajouter_client();
    }
    if(i==2){
        modifier_client();
    }
    if(i==3){
        supprimer_client();
    }
    if(i==4){
        afficher_les_clients();
    }
    if(i==5){
        main();
    }

    }
void menu_voiture(){
    int i ;
    puts("Menu Voiture");
    puts("1-Ajouter Un Voiture");
    puts("2-Modifier Un Voiture");
    puts("3-Supprimer Un Voiture");
    puts("4-Afficher La Liste Des Voiture");
    puts("5-Retourner AU menu");
    puts("CHOISISSZR ENTRE 1 ET 5 ");
    scanf("%d",&i);
    system("cls");
    if(i==1){
        ajouter_voiture();
    }
    if(i==2){
        modifier_voiture();
    }
    if(i==3){
        supprimer_voiture();
    }
    if(i==4){
        afficher_les_voitures();
    }
    if(i==5){
        main();
    }
    }
void menu_commande(){
   int i ;
    puts("Menu Commande");
    puts("1-Ajouter Une Commande");
    puts("2-Afficher La Liste Des Commandes");
    puts("3-Afficher La Liste Des Commandateurs");
    puts("4-Retourner AU menu");
    puts("CHOISISSZR ENTRE 1 ET 4 ");
    scanf("%d",&i);
    system("cls");
    if(i==1){
        ajouter_commande();
    }
    if(i==2){
        afficher_les_commandes();
    }
    if(i==3){
        afficher_les_commandateurs();
    }
    if(i==4){
        main();
    }

    }

void menu(){
    int i ;
    puts("Menu");
    puts("1-Gestion Des Clients");
    puts("2-Gestion Des Voitures");
    puts("3-Gestion Des Commandes");
    puts("CHOISISSZR ENTRE 1 ET 3 ");

    scanf("%d",&i);
    system("cls");
    if(i==1){
        menu_client();
    }
    if(i==2){
        menu_voiture();
    }
    if(i==3){
        menu_commande();
    }

}
void modifier(struct client *q){
   // puts("modifier ce client :");
    afficher_client(*q);
    entrer_client(q);
    }
void v_modifier(struct voiture *q){
   // puts("modifier ce client :");
    afficher_voiture(*q);
    entrer_voiture(q);
    }

int main()
{
    creer_liste(&ll);
    v_creer_liste(&lv);
    c_creer_liste(&lc);
    menu();

    return 0;
}
