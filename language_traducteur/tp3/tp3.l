%{
    int nbLign = 1;
%}

%%

\n                     {nbLign ++;}
si                    {return SI;}
alors                 {return ALORS;}
programme             {return PROGRAMME;}
declare               {return DECLARE;}
naturel               {return NATUREL;}
caractere             {return CARACTERE;}
booleen               {return BOOLEEN;}
debut                 {return DEBUT;}
fin                   {return FIN;}
sinon                 {return SINON;}
fsi                   {return FSI;}
tantque               {return TANTQUE;}
faire                 {return FAIRE;}
ftq                   {return FTQ;}
obtenir               {return OBTENIR;}
afficher              {return AFFICHER;}
affichaine            {return AFFICHAINE;}
alaligne              { return ALALIGNE;}
ou                    {return OU;}
et                    {return ET;}
non                   {return NON;}
vrai                  {return VRAI;}
faux                  {return FAUX;}
\)                    {return PF;}
\+                    {return PLUS ;}
\-                    {return MINUS ;}
\*                    {return MULT;}
\/                    {return DIVIDE ;}
\:\=                  {return EQUAL;}
\<                    {return LESS;}
\<\=                  {return LESS_EQUAL;}
\>                    {return MORE;}
\>\=                  {return MORE_EQUAL;}
\=\=                  {return EQUAL_EQUAL;}
\!\=                  {return NOT_EQUAL;}
\;                    {return PV;}
\.                    {return POINT;}
\(                    {return PO;}
\'[^']\'              {return CAR;}
\"[^"]*\"            {return CHAINE;}
[0-9]*               {return NOMBRE;}
[a-zA-Z][a-zA-Z0-9]* {return IDENT;}

%%
