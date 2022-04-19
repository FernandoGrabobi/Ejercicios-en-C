#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/***************** ESTRUCTURA ********************/

/**     AUTOR     **/

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int dni;
    char nacionalidad[20];
} Autor;

/**     BIBLIOTECA     **/

typedef struct
{
        int isbm;
        char nombre[20];
        int edicion;
        char tipo[20];
        char editoral[20];
        int cantidad;
        int autores[5];     /* SE GUARDA EL ID DEL AUTOR */
        int disponible;     /* VALOR -1 : NO DISPONIBLE |  VALOR 1 : DISPONIBLE  */
} Biblioteca;

/**     PERSONA     **/

typedef struct
{       int dni;
        char nombre[20];
        int prestamos[3];
        int multa;
} Persona;

/**     FECHA     **/

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

/**     PRESTAMO     **/

typedef struct
{       int id;
        int libro;
        Fecha inicio;
        Fecha fin;
        int dias;
} Prestamo;

/***************** FUNCIONES ********************/

    /**     INICIALIZO LOS ARREGLOS DEL MAIN   **/

    void iniciarPrestamos(Prestamo *pPrestamo,int max){
        int j,h;
        for(j = 0; j<max; j++){
            pPrestamo[j].id = -1;
            pPrestamo[j].libro = -1;
            pPrestamo[j].dias = 0;
            pPrestamo[j].inicio.dia = 0;
            pPrestamo[j].inicio.mes = 0;
            pPrestamo[j].inicio.anio = 0;
            pPrestamo[j].fin.dia = 0;
            pPrestamo[j].fin.mes = 0;
            pPrestamo[j].fin.anio = 0;

        }
    }

    void iniciarAutores(Autor *pAutor,int max){
        int j,h;
        for(j = 0; j<max; j++){
            for(h = 0; h<20; h++){
                pAutor[j].nombre[h] = '\0';
                pAutor[j].apellido[h] = '\0';
                pAutor[j].nacionalidad[h] = '\0';
            }
            pAutor[j].dni = 0;
            pAutor[j].id = -1;
        }
    }
    void inicializarStruc(Biblioteca *pLibro,int max){
       int j;
       for(j = 0; j<max; j++){
        /*  Llamo la funcion vaciar (un elemento del arreglo de Biblioteca [max])*/
           vaciar(pLibro,j);
        }
    }

    void cargarLibro(Biblioteca *pLibro, int n){
        /* J es la posicion 5 de los 10 que estamos usando por ahora*/
    int j = 0 ;
            /*   PRIMER LIBRO POSICION 0  */
            (pLibro[j]).nombre[0]='A';
            (pLibro[j]).nombre[1]='B';
            (pLibro[j]).nombre[2]='C';
            (pLibro[j]).edicion= 10;
            (pLibro[j]).tipo[0]='B';
            (pLibro[j]).editoral[0]='2';
            (pLibro[j]).cantidad = 10;
            (pLibro[j]).isbm = 100+j;
            (pLibro[j]).disponible = 1;
            (pLibro[j]).autores[0] = 0;
            (pLibro[j]).autores[1] = 1;

            /*   PRIMER LIBRO POSICION 1  */
            j++;
            (pLibro[j]).nombre[0]='T';
            (pLibro[j]).nombre[1]='N';
            (pLibro[j]).nombre[2]='T';
            (pLibro[j]).edicion= 5;
            (pLibro[j]).tipo[0]='A';
            (pLibro[j]).editoral[0]='6';
            (pLibro[j]).cantidad = 20;
            (pLibro[j]).isbm = 100+j;
            (pLibro[j]).disponible = 1;
            (pLibro[j]).autores[0] = 0;

            /*   PRIMER LIBRO POSICION 3  */
            j++;
            (pLibro[j]).nombre[0]='B';
            (pLibro[j]).nombre[1]='B';
            (pLibro[j]).nombre[2]='C';
            (pLibro[j]).edicion= 2;
            (pLibro[j]).tipo[0]='A';
            (pLibro[j]).editoral[0]='G';
            (pLibro[j]).cantidad = 5;
            (pLibro[j]).isbm = 100+j;
            (pLibro[j]).disponible = 1;
            (pLibro[j]).autores[0] = 0;
    }
    void preCargarAutores(Autor *pAutor){
        /*PRIMER AUTOR POSICION 0*/
        pAutor[0].nombre[0] = 'L';
        pAutor[0].nombre[1] = 'u';
        pAutor[0].nombre[2] = 'i';
        pAutor[0].nombre[3] = 's';
        pAutor[0].apellido[0] = 'F';
        pAutor[0].nacionalidad[0] = 'A';
        pAutor[0].nacionalidad[1] = 'r';
        pAutor[0].dni = 20500500;
        pAutor[0].id = 0;

        /*PRIMER AUTOR POSICION 1*/
        pAutor[1].nombre[0] = 'E';
        pAutor[1].nombre[1] = 'l';
        pAutor[1].nombre[2] = 'i';
        pAutor[1].nombre[3] = 'a';
        pAutor[1].nombre[4] = 's';
        pAutor[1].apellido[0] = 'M';
        pAutor[1].nacionalidad[0] = 'E';
        pAutor[1].nacionalidad[1] = 's';
        pAutor[1].dni = 10250250;
        pAutor[1].id = 1;

    }

    /**     Vacio un elemento del miembro de Biblioteca[max]   **/

void vaciar(Biblioteca *pLibro, int j){
    int i,h;
    for(i=0; i<20; i++){        /*20 por que el char es de tamaño 20*/
        /*  PARTE DEL LIBRO */
        (pLibro[j]).nombre[i]='\0';
        (pLibro[j]).tipo[i] = '\0';
        (pLibro[j]).editoral[i] = '\0';
    };
        (pLibro[j]).edicion = 0;
        /*  PARTE DEL LIBRO */
        (pLibro[j]).cantidad = 0;
        (pLibro[j]).isbm = -1;
        (pLibro[j]).disponible = -1;
        /*  PARTE DL AUTOR  */
     for(h=0; h<5; h++){
        (pLibro[j]).autores[h] = -1;
     }
}

bool comparaStr (char entrada[],char modelo[]){
    int ind = 0;

    while (entrada[ind]!='\0' && modelo[ind]!='\0' && entrada[ind] == modelo[ind]){
        ind++;
    }

    if (entrada[ind]!='\0' || modelo[ind]!='\0')
       return false;

    return true;
}
/***************** MINI FUNCIONES ********************/

int isbnLibroToPosicionLibro(Biblioteca *pLibro, int max, int posicion){
    int i;
    int v;      /*   VARIABLE QUE GUARDARA LA POSICION Y SE RETORNARA   */
    for(i = 0; i<max; i++){
        if(pLibro[i].isbm == posicion){      /*   SI EL VALOR DE POSICION (QUE ES LA EDICION) COINCIDE CON UNO DE LOS LIBROS DEL ARREGLO LIBRO: ENTRA   */
            v = i;
            break;
        }
    }
    return v;
}

/***    RECIBE DOS ARREGLOS, AUXARRAY ES DONDE SE GUARDARA EL ARREGLO ORDENADO    ****/
void ordenamientoBurbuja(Biblioteca *pLibro, int max, int *auxArray, int maxAux){
    int i = 0;  /*   PARA POSICIONAR EL DATO DE LIBRO->EDICION EN UN EL auxArray[I]   */
    int f,g,h;      /*   h PARA EL for   */
    int aux[maxAux];
    int auxID[maxAux];  /*  GUARDARA LOS ID/ISBN EN SINCRONIA CON LOS VALORES EDICION    */
    int u;      /*   GUARDARA EL VALOR DE LA POSICION DEL LIBRO MAS ADELANTE   */

        /*   COPIADO DE DATOS EDICION EN auxArray (POR SI EXISTEN ESPACIOS VACIOS ENTRE LOS ELEMENTOS DEL ARREGLO pLibro)   */
        for(h=0; h<max; h++){
            if(pLibro[h].disponible != -1){         /*   SI NO ESTA VACIO ENTRA EN EL IF   */
                auxArray[i] = pLibro[h].edicion;    /*   COPIA EL DATO DE EDICION EN EL ARREGLO auxArray   */
                auxID[i] =  pLibro[h].isbm;         /*   GUARDO LA ID, LA POSICION DE LA EDICION Y LA ID COINCIDEN       */
                i++;
            }
        }

        /*
        ESTE FOR ME IMPRIME EL ORDEN ORGINAL DE LA EDICION


        for(f=0; f<maxAux; f++){
            u = isbnLibroToPosicionLibro(pLibro, max,auxID[f]);     /*DEVUELVE LA POSICION DEL LIBRO QUE COINCIDE CON ESTA EDICION
            printf("LIBRO: %s *** EDICION: %d \n" ,pLibro[u].nombre,auxArray[f]);
        }

        */
        /**    ORDENAR     **/
        int save;       /*   COMO AUXILIAR PARA SALVAR UNO DE LOS DATOS A INTERCAMBIAR (EDICION)   */
        int id_save;    /*   COMO AUXILIAR PARA SALVAR UNO DE LOS DATOS A INTERCAMBIAR (ID)  */
        for(g=0; g<maxAux; g++){
            for(f=0; f<maxAux; f++){   /*   RECORRO EL LARGO DEL NUEVO ARREGLO AUX, ESTE ES IGUAL AL NUMERO DE LIBROS EXISTENTES   */
                if(auxArray[f+1] != NULL){  /*   COMO PARA ORDENARLO TENGO QUE COMPARARLO CON EL SIGUIENTE, PRIMERO VERIFICO QUE EL SIGUIENTE EXISTA   */
                    if(auxArray[f]>auxArray[f+1]){      /*   SI EL ANTERIOR [f] ES MAYOR QUE EL SIGUIENTE [f+1] LOS TENGO QUE INTERCAMBIAR   */
                        /*   INTERCAMBIAR EDICION   */
                        save = auxArray[f];
                        auxArray[f] = auxArray[f+1];
                        auxArray[f+1] = save;
                        /*   INTERCAMBIAR ID   */
                        id_save = auxID[f];
                        auxID[f] = auxID[f+1];
                        auxID[f+1] = id_save;

                    }
                }
            }
        }

        for(f=0; f<maxAux; f++){
            u = isbnLibroToPosicionLibro(pLibro, max,auxID[f]);
            printf("LIBRO: %s *** EDICION: %d \n",pLibro[u].nombre,auxArray[f]);
        }
        return;
}

bool estaVacio(Biblioteca *pLibro,int max, int isbm){
    int i;
    bool esVacio = true;
    for (i = 0; i<max; i++){
        if(pLibro[i].isbm == isbm){
            esVacio =  false;
        }
    }
    /** SI ESTA VACIO DEVUELVE TRUE - CASO CONTRARIO FALSE **/
    return esVacio;
}
/**     DEVUELVE LA PRIMERA POSICION VACIA DEL ARREGLO DE AUTORES[MAX]      **/

int existeAutorVacio(Autor *pAutor,int max){
    int i;
    for (i = 0; i<max; i++){
        if(pAutor[i].id == -1){    /*   SI SE ENCUENTRA UN ID -1 SIGNIFICA QUE HAY UNA POSICION VACIA PARA INSERTAR UN AUTOR    */
            return i;              /*   DEVUELVO POSICION i    */
        }
    }
}

/**     DEVUELVE TRUE SI EXISTE AL MENOS UN AUTOR CARGADO EN EL ARREGLO AUTORES[MAX]    **/

bool existeAutor(Autor *pAutor, int max){
    bool v = false;
    int i;
    for(i = 0; i<max; i++){
        if(pAutor[i].id != -1){    /*   SI ENCUENTRA UN ID DISTINTO DE -1 SIGNIFICA QUE HAY UN AUTOR CARGADO   */
            v = true;              /*   CAMBIO A TRUE POR QUE EXISTE UN AUTOR CARGADO EN EL ARREGLO AUTORES    */
            break;                 /*   TERMINO EL CICLO    */
        }
    }
    return v;
}

bool controlRangoInt(int valor, int min, int max){
    /** SI EL VALOR ESTA DENTRO DEL RANGO DEVUELVE TRUE**/
    if(min <= valor && valor <=max){
        return true;
    }else{
        return false;
    }
}

/**     POR MEDIO DEL ID DENTRO DE USUARIO->PRESTAMOS[ID] (RANGO 3)
        BUSCAR ID DENTRO DEL ARREGLO PRESTAMOS[i]->ID Y ESTRAER PRESTAMOS[i]->LIBRO   **/

int IDprestamoToISBNlibro(Biblioteca *pLibro,int max, Prestamo *pPrestar, int id){
    int i, r;
    bool noExiste = true;
    for(i = 0; i<max; i++){
        if(id == pPrestar[i].id){   /*   CONTROLO SI EXISTE EL ID PRESTAMO DENTRO DEL ARREGLO PRESTAMO    */
            r = pPrestar[i].libro;  /*   SI EXISTE GUARDO EL ID/ISBN DEL LIBRO DENTRO DEL PRESTAMO ENCONTRADO    */
        noExiste = false;           /*   COMO EXISTE UN ID ENTONCES NO HACE FALTA EL MENSAJE DE ABAJO, POR LO TANTO LO CANBIO A FALSE PARA QUE NO ENTRE EN EL IF  */
        break;
        }
    }
    if(noExiste){
        printf("NO EXISTE! \n");
    }
    return r;
}

/**     ESTA FUNCION RECIBE UNA ID Y SI DEVUELVE TRUE ES POR QUE EXISTE LA ID EN EL ARREGLO AUTOR   **/

bool buscarIDtoAutorID(Autor *pAutor, int max, int id){
    int i;
    bool v = false;                 /*   INICIALIZO COMO FALSE   */
    for(i = 0; i<max; i++){         /*   RECORRO EL LARGO DEL ARREGLO AUTOR [MAX]   */
        if(pAutor[i].id == id){     /*   SI EL ID COINCIDE CON UNO DE LOS ID DEL ARREGLO EN AUTOR ENTRA EN EL IF   */
            v = true;               /*   CAMBIAMOS A TRUE POR QUE EXISTE EL ID   */
        }
    }
    return v;                       /*   RETORNAMOS V   */
}
/**    RECIBE UN ID DE LIBRO Y DEVUELVE LA POSICION EN DONDE SE ENCUENTRA EN EL ARREGLO LIBRO[MAX]    **/

int idLibroTOposicionLibro(Biblioteca *pLibro,int max, int id){     /*   RECIBE UNA ID/ISBN Y RETORNA LA POSICION DEL ARREGLO DONDE SE ENCUENTRA   */
    int i;
    for(i = 0; i<max; i++){
        if(pLibro[i].isbm == id ){
            return i;

        }
    }
}

/**    RECIBE UN ID DE AUTOR Y DEVUELVE LA POSICION EN DONDE SE ENCUENTRA EN EL ARREGLO AUTORES[MAX]    **/

int idAutorTOposicionAutor(Autor *pAutor,int max, int id){     /*   RECIBE UNA ID/ISBN Y RETORNA LA POSICION DEL ARREGLO DONDE SE ENCUENTRA   */
    int i, aux;
    for(i = 0; i<max; i++){
        if(pAutor[i].id == id ){
           aux = i;
           break;
        }
    }
    return aux;
}

void addFechas(Persona *usuario, Prestamo *pPrestar, int index){
    int dia, mes, anio;
    /*   index ES LA POSICION EN LA QUE SE ENCUENTRA EL ELEMENTO Prestamo   */
    printf("DIA INGRESE UN VALOR ENTRE 1 Y 30: ");
    do{
        scanf("%d",&dia);
        if(controlRangoInt(dia,1,30)){
            pPrestar[index].inicio.dia = dia;
        }else {
            printf("ERROR INGRESE UN VALOR ENTRE 1 Y 30!\n");
        }
    }while(!controlRangoInt(dia,1,30));

    printf("MES INGRESE UN VALOR ENTRE 1 Y 12: ");
    do{
        scanf("%d",&mes);
        if(controlRangoInt(mes,1,12)){
            pPrestar[index].inicio.mes = mes;
        }else{
            printf("ERROR! INGRESE UN VALOR ENTRE 1 Y 12\n");
        }
    }while(!controlRangoInt(mes,1,12));

    printf("ANIO INGRESE UN VALOR ENTRE 2018 Y 2020 : ");
    do{
        scanf("%d",&anio);
        if(controlRangoInt(anio,2018,2020)){
            printf("%d",anio);
             pPrestar[index].inicio.anio = anio;
        }else{
             printf("ERROR! INGRESE UN VALOR ENTRE 2018 Y 2020\n");
        }
    }while(!controlRangoInt(anio,2018,2020));

    int auxDia,auxMes, auxAnio;
    /** SUMA DE DIAS ENCONTRAR LA FECHA LIMITE **/
    auxDia = dia + 30;
    if(auxDia>30){

        pPrestar[index].fin.dia = auxDia - 30;
        auxMes = mes + 1;
        if(auxMes>12){
            pPrestar[index].fin.mes = auxMes - 12; /*RESULTADO 13-12 = 1*/
            auxAnio = anio + 1;                    /*RESULTADO N + 1 = SIGUIENTE ANIO*/
            pPrestar[index].fin.anio = auxAnio;

        }else{
            pPrestar[index].fin.mes = auxMes;      /*RESULTADO MES + 1 = ESTE SIEMPRE SERA ENTRE auxMes<13*/
            pPrestar[index].fin.anio = anio;       /*   MISMO ANIO*/
        }
    }
    /* MUESTRO LAS FECHAS DENTRO PRESTAMOS -> FECHAS [DIA - MES - ANIO]*/
    printf("FECHA DE INICIO: %d - %d - %d \n",pPrestar->inicio.dia,pPrestar->inicio.mes,pPrestar->inicio.anio);
    printf("FECHA DE FIN:    %d - %d - %d \n",pPrestar->fin.dia,pPrestar->fin.mes,pPrestar->fin.anio);
}

/*MOSTRAR DATOS DEL LIBRO*/

void mostrarLibro(Biblioteca *pLibro, int max, Autor *pAutor, int libro_isbn){
    printf("**  DATOS ACTUALES DEL LIBRO    **\n");
    int p = libro_isbn;         /*   p ES LA POSICION DEL LIBRO QUE DEBEMOS MOSTRAR   */
    /*int p = idLibroTOposicionLibro(pLibro, max, libro_isbn); /*  P POSICION DEL LIBRO QUE COINCIDE CON EL ISBN   */

    printf("* NOMBRE: %s\n",pLibro[p].nombre);
    printf("* EDITORIAL: %s\n",pLibro[p].editoral);
    printf("* EDICION: %d\n",pLibro[p].edicion);
    printf("* TIPO: %s\n",pLibro[p].tipo);
    printf("* DISPONIBILIDAD: %d\n",pLibro[p].disponible);
    int i,posicionAutor = 0;

    for(i = 0; i<5;i++){
        if(pLibro[p].autores[i] != -1){             /*   SI ES DISTINTO DE -1 SIGNIFICA QUE EXISTE UN AUTOR DENTRO EL ESPACIO LIBRO->AUTORES[i]   */
            posicionAutor = pLibro[p].autores[i];   /*      */
            printf("AUTOR %d : %s %s\n",i+1,pAutor[posicionAutor].nombre,pAutor[posicionAutor].apellido);
        }
    }
}

void mostrarPrestamos(Biblioteca *pLibro, int max, Persona *usuario, Prestamo *pPrestar){
    /**     ENTRO EN USUARIO -> PRESTAMOS   **/
    printf("USUARIO 1: \n");
    int i,j,h;
    for(i = 0; i<3; i++){
        if(usuario->prestamos[i] != -1){ /*  SI USUARIO->PRESTAMOS[i] NO ESTA VACIO LO MUESTRO*/

            printf("PRESTAMO -> %d : Libro[ISBM %d] \n",i+1, IDprestamoToISBNlibro(pLibro,max, pPrestar, usuario->prestamos[i]));

        }else{
            printf("ESTA VACIO %d\n",usuario->prestamos[i]);
        }

    }

}
bool fechaCorrecta(int diaI, int mesI, int anioI, int diaF, int mesF, int anioF){
    bool diaError = true;
    if(anioF<anioI){
        diaError = false;
    }else{
        if(mesF<mesI){
            diaError = false;
        }else{
            if(diaF < diaI){
                diaError = false;
            }
        }
    }
    return diaError;
}

int diferenciaFecha(int diaI, int mesI, int anioI, int diaF, int mesF, int anioF){
    int aux, diasTotales = 0;
    int diasIniciales = 0;
    int diasFianles = 0;
    if(fechaCorrecta(diaI, mesI, anioI, diaF, mesF, anioF)){
        diasIniciales = (diaI) + (mesI*30) + (anioI*365);
        diasFianles = (diaF) + (mesF*30) + (anioF*365);
    }
    diasTotales = diasFianles - diasIniciales ;
    return diasTotales;
}

/**     MUESTRA TODOS LOS AUTORES CARGADOS EN EL ARREGLO AUTORES    **/

void mostrarAutores(Autor *pAutor, int max){
    printf("        -       AUTORES     -        -  : \n");
    int i,j,h;
    for(i = 0; i<max; i++){
        if(pAutor[i].id != -1){ /*  SI USUARIO->PRESTAMOS[i] NO ESTA VACIO LO MUESTRO*/
            printf(" [%d]- %s %s [ID: %d]\n",i,pAutor[i].nombre,pAutor[i].apellido,pAutor[i].id);
        }else{
        }
    }
}

/***************** ABM ********************/

void devolucion(Biblioteca *pLibro, int max, Persona *usuario, Prestamo *pPrestamo){
    int j,k;
    int i,g = 1;
    int posicion_k;
    bool mensaje = true;
    int salir = 0;

        int diaI;
        int mesI;
        int anioI;
        int dia, mes, anio;

        printf("DIAS DE DIFERENCIA: %d",diferenciaFecha(diaI,mesI,anioI,dia,mes,anio));

        for(i = 0; i<3; i++){ /*   RECORRER    USUARIO->PRESTAMOS[3]    */
            printf("MOSTRAR: %d \n",pPrestamo[usuario->prestamos[i]].libro);
        }
        printf("INGRESE EL ISBN QUE DESEA DEVOLVER:\n");

        do{
        scanf("%d", &j);
        /*   SI MUESTRA DISTINTO DE MENOS -1 SIGNIFICA QUE TIENE UN PRESTAMOS EN ESA POSICION   */
        for(k = 0; k<3;k++){
            if(pPrestamo[usuario->prestamos[k]].libro == j){      /*   EL IBM ES CORRECTO AL    */

                /*   OBTENGO LOS ATRIBUTOS DE LA FECHA DE INICIO DEL PRESTAMOS   */
                diaI = pPrestamo[usuario->prestamos[k]].inicio.dia;
                mesI = pPrestamo[usuario->prestamos[k]].inicio.mes;
                anioI = pPrestamo[usuario->prestamos[k]].inicio.anio;

            do{     /*   SE  do SE REPETIRA SIEMPRE QUE QUE LA FECHA DE DEVOLUCION INGRESADA SEA MENOR   */
                printf("INGRESE LA FECHA DEL PRESTAMOS : (%d-%d-%d)\n",diaI,mesI,anioI);
                printf("INGRESE LA FECHA DE DEVOLUCION :\n");
                printf("DIA INGRESE UN VALOR ENTRE 1 Y 30: ");
                do{
                    scanf("%d",&dia);
                    if(controlRangoInt(dia,1,30)){
                    }else {
                        printf("ERROR INGRESE UN VALOR ENTRE 1 Y 30!\n");
                    }
                }while(!controlRangoInt(dia,1,30));

                printf("MES INGRESE UN VALOR ENTRE 1 Y 12: ");
                do{
                    scanf("%d",&mes);
                    if(controlRangoInt(mes,1,12)){
                    }else{
                        printf("ERROR! INGRESE UN VALOR ENTRE 1 Y 12\n");
                    }
                }while(!controlRangoInt(mes,1,12));


                printf("ANIO INGRESE UN VALOR ENTRE 2018 Y 2020 : ");
                do{
                    scanf("%d",&anio);
                    if(controlRangoInt(anio,2018,2020)){
                    }else{
                         printf("ERROR! INGRESE UN VALOR ENTRE 2018 Y 2020\n");
                    }
                }while(!controlRangoInt(anio,2018,2020));

                if(!fechaCorrecta(diaI, mesI, anioI, dia,mes,anio)){
                    printf("FECHA INGRESADA . INCORRECTA\n\n");
                }
            }while(!fechaCorrecta(diaI, mesI, anioI, dia,mes,anio));
            printf("FECHA CORRECTA\n");
            printf("DIA DE ENTREGA    : %d %d %d\n",diaI,mesI,anioI);
            printf("DIA DE DEVOLUCION : %d %d %d\n",dia,mes,anio);
            int dias_Transcurridos = diferenciaFecha(diaI,mesI,anioI,dia,mes,anio); /* PRIMERO SE ENVIA LOS DATOS DE LA FECHA DE INICIO Y LUEGO DE LA FECHA FINAL*/
            if(dias_Transcurridos>30){
                printf("SE PASO EL EL TIEMPO LIMITE\n");
                int multa = (dias_Transcurridos-30)*2;      /*   FORMULA DE MULTA, 2 DIAS POR DIAS ATRASADOS   */
                printf("DIAS ATRASADOS EN LA ENTREGA DEL LIBRO\n",multa);
                printf("TIENE UNA MULTA DE : %d DIAS\n",multa);
                usuario->multa = multa;         /*AGREGO LA MULTA AL ATRIBUTO MULTA  DE USUARIO*/

            }else{
                printf("LIBRO ENTREGADO A TIEMPO\n");
            }


                usuario->prestamos[k] = -1;
                g = 0;
                printf("\n");
                printf("PRESTAMO BORRADO - VALOR: %d\n",usuario->prestamos[k]);
                pPrestamo[usuario->prestamos[k]].dias = 0;
                pPrestamo[usuario->prestamos[k]].inicio.dia = 0;
                pPrestamo[usuario->prestamos[k]].inicio.mes = 0;
                pPrestamo[usuario->prestamos[k]].inicio.anio = 0;
                pPrestamo[usuario->prestamos[k]].libro = -1;
                pPrestamo[usuario->prestamos[k]].fin.dia = 0;
                pPrestamo[usuario->prestamos[k]].fin.mes = 0;
                pPrestamo[usuario->prestamos[k]].fin.anio = 0;

                int v = idLibroTOposicionLibro(pLibro,max,j);
                pLibro[v].cantidad++;
                printf("CANTIDAD DE LIBROS: %d\n",pLibro[v].cantidad);
                mensaje = false;
                break;
                }
            }
            if(mensaje){
                printf("ESTE LIBRO NO FUE PRESTADO");
            }
        }while(g == 1);

}
void mostrarFuncionFinal(Biblioteca *pLibro, int max, Autor *pAutor){
    printf("***           MENU MOSTRAR         ***\n");
    printf(" 1 - DADO UN AUTOR MOSTRAR LOS LIBROS\n");
    printf(" 2 - DADO UN LIBRO MOSTRAR LOS AUTORES\n");
    printf(" 3 - ORDENAR LOS LIBROS POR EDICION\n");
    printf(" 4 - MOSTRAR LIBROS\n");
    printf(" 0 - SALIR\n\n");
    int a;      /*   a OPCION   */
    int b;      /*   b SUB-OPCION   */
    int f;      /*   f PARA LOS for   */

    /*   VARIABLES PARA CASE 3   */
    int contador = 0;
    int auxArray[contador];    /*   CREO UN ARREGLO CON EL TAMANIO EXACTO DE ELEMENTOS DISPONIBLES   */
    int *pAuxArray;
    pAuxArray = &auxArray;  /*   LO HAGO PUNTERO PARA TRABAJRLO EN LA FUNCION   */

    bool noExisteLibro = true;  /*   PARA MOSTRAR UN MENSAJE DE NO SE ENCONTRO UN LIBRO   */
    bool noExisteAutor = true;  /*   PARA MOSTRAR UN MENSAJE DE NO SE ENCONTRO UN UN AUTOR   */
    do{
        scanf("%d",&a);
        switch(a){
        case 1:
            printf("INGRESE UN EL ID DE UN AUTOR\n");
            scanf("%d",&b);
            for(f = 0; f<max; f++){     /*   RECORRO TODOS LAS POSICIONES DE LIBROS   */
                if(pLibro[f].disponible != -1 ){       /*   CONTROLO QUE EL LIBRO EXISTA O ESTE DISPONIBLE (DISTINTO DE -1)   */
                    int g;
                    for(g = 0; g<5 ;g++){     /*   RECORRO EL ARREGLO AUTORES DENTRO DE LIBROS LIBROS->AUTORES[5]  */
                        if(pLibro[f].autores[g] != -1 && pLibro[f].autores[g] == b){  /*   SI LIBRO->AUTORES[g] ES DISTINTO DE -1 SIGNIFICA QUE EXISTE UN AUTOR EN ESE ELEMENTO */
                            printf(" - LIBRO : %s \n",pLibro[f].nombre);
                            noExisteAutor = false;  /*    COMO EXISTE UN AUTOR LO VOLVEMOS FALSE PARA EVITAR QUE ENTRE EN EL MENSAJE DE ABAJO     */
                        }
                    }
                noExisteLibro = false;      /*   COMO EXISTE UN LIBRO LO VOLVEMOS FALSE PARA EVITAR QUE ENTRE EN EL MENSAJE DE ABAJO     */
                a = 0;
                }
            }
            if(noExisteAutor){
             printf("NO EXISTE AUTOR(S)\n");

            }else{
                if(noExisteLibro) {
                    printf("NO EXISTE LIBRO(S)\n");

                }
            }
            system("pause");
            break;
        case 2:

            printf("INGRESE UN EL ISBN DE UN LIBRO PARA MOSTRAR LOS AUTORES\n");
            scanf("%d",&b);
            noExisteLibro = true;  /*   PARA MOSTRAR UN MENSAJE DE NO SE ENCONTRO UN LIBRO   */
            for(f = 0; f<max; f++){     /*   RECORRO TODOS LAS POSICIONES DE LIBROS   */
                if(pLibro[f].disponible != -1 && pLibro[f].isbm == b){       /*   CONTROLO QUE EL LIBRO EXISTA O ESTE DISPONIBLE (DISTINTO DE -1)   */
                    int g;
                    int autor_posicion;       /*   VARIABLE PARA GUARDAR LA POSICION DEL AUTOR Y LUEGO OBTENER SUS DATOS    */
                    for(g = 0; g<5 ;g++){     /*   RECORRO EL ARREGLO AUTORES DENTRO DE LIBROS LIBROS->AUTORES[5]  */
                        if(pLibro[f].autores[g] != -1){  /*   SI LIBRO->AUTORES[g] ES DISTINTO DE -1 SIGNIFICA QUE EXISTE UN AUTOR EN ESE ELEMENTO */
                            autor_posicion = idAutorTOposicionAutor(pAutor,max, pLibro[f].autores[g]);      /*   OBTENER LA POSICION DEL AUTOR MEDIANTE LA ID DEL AUTOR, LIBRO->AUTOR[g]   */
                            printf(" - AUTOR : %s %s \n",pAutor[autor_posicion].nombre,pAutor[autor_posicion].apellido);
                            noExisteAutor = false;  /*    COMO EXISTE UN AUTOR LO VOLVEMOS FALSE PARA EVITAR QUE ENTRE EN EL MENSAJE DE ABAJO     */
                        }
                    }
                a = 0;
                noExisteLibro = false;      /*   COMO EXISTE UN LIBRO LO VOLVEMOS FALSE PARA EVITAR QUE ENTRE EN EL MENSAJE DE ABAJO     */
                }
            }
            if(noExisteLibro) {
                printf("NO EXISTE LIBRO(S)\n");

            }
            system("pause");
            break;
        case 3:
                 /*   CONTADOR PARA SABER EL TAMANIO DEL ARRAY AUX QUE TENDRA LOS VALORES DE EDICION Y PODER ORDEBARLOS   */
            for(f = 0; f<max;f++){
                if(pLibro[f].disponible != -1){
                    contador++;
                }
            }

            ordenamientoBurbuja(pLibro,max,pAuxArray,contador);
            a = 0;
            system("pause");
            break;
        case 4:
            mostrarLista(pLibro,max);
            a = 0;
            system("pause");
            break;
        };

    }while(a!=0);
}

void prestamoLibro(Biblioteca *pLibro, int max, Persona *usuario, Prestamo *pPrestar){
    printf("PRESTAMOS DE LIBRO\n");

    /* -> si la estructura no es un arreglo (usuario es solo 1)*/
    /* .  si la estructura es un arreglo (pLlibro son 3)*/

    /*AGREGAR USUARIO A PRESTAMO -> USUARIO (DNI)*/
    int isbm,i,h=0;
    bool exit = true;
    int lleno = 0;

    /*   CUENTO LOS ESPACIOS DE USUARIO->PRESTAMOS  */
    for(i = 0; i<3; i++){
        if(usuario->prestamos[i] != -1){        /*    SI SON DISTINTOS DE -1 ES POR QUE ESTAN OCUPADOS  */
            lleno++;                            /*    LO SUMO PARA AL FINAL MOSTRAR EL MENSAJE      */
        }
    }
            /* BUSCAR SI TENGO UN ESPACIO PARA AGREGAR EL IBMS DEL LIBRO.
            SI SE ENCUETRA LO GUARDO EN UN LUGAR VACIO*/
    do{ /*  RECORRO EL ARREGLO PRESTAMOS h = posicion */
        if(pPrestar[h].id == -1 && h<max){ /*    SI ENCUENTRO SLOT VACIO [-1] ACCEDO PARA INSERTAR DATOS   */
            for(i = 0; i<3; i++){ /*    RECORRO PARA VER SI USUARIO->PRESTAMOS[X] ESTA VACIO   */
                if(usuario->prestamos[i] == -1){
                    pPrestar[h].id = i;
                    /** ESCOJA EL IBSM QUE SE GUARDA EN LOS LIBROS DEL USUARIO **/
                    printf("Escoja el Libro que se prestara (IBMS)\n");
                    do{
                    scanf("%d", &isbm);
                    /**     RECORRO PARA VER SI EXISTE LA ISBM DEL LIBRO DADA POR EL USUARIO**/
                    if(!estaVacio(pLibro,max,isbm)){


                        pPrestar[h].libro = isbm; /*    ATRIBUTO LIBRO AGREGADO a PRESTAMO     */
                        usuario->prestamos[i] = pPrestar[h].id; /*    ATRIBUTO PRESTAMO[i] AGREGADO a USUARIO     */
                        printf("LIBRO AGREGADO!\n");
                        int v = idLibroTOposicionLibro(pLibro,max,isbm);
                        pLibro[v].cantidad--;
                        printf("CANTIDAD DE LIBROS: %d\n",pLibro[v].cantidad);
                        /** CAMBIO A FALSE PARA SALIR DEL CICLO WHILE**/
                        exit = false;
                        break;
                    }else{
                        printf("LIBRO NO ENCONTRADO INTENTELO DE NUEVO!\n");
                    }
                    }while(exit);

                    /** AGREGAR FECHAS**/

                    printf("INGRESE LA FECHA\n");

                    addFechas(usuario, pPrestar, h );   /*  FECHAS DE INICIO Y FIN AGREGADAS a PRESTAMO */
                    pPrestar[h].dias = 0;
                    break;      /** BREAK PARA TERMINAR EL FOR**/
                }
            }
            if(lleno == 3){         /*    LA VARIABLE LLENO' ES UN CONTADOR SI EL USUARIO TIENE 3 PRESTAMOS ESTE IF SE CUMPLE      */
                printf("EL USUARIO YA TIENE 3 PRESTAMOS DE LIBROS\n");
            }
            /*SALIR DEL WHILE*/
            break;
        }
        h++;
    }while(exit);
    /*  ERROR   */
    mostrarPrestamos(pLibro,max,usuario,pPrestar);
    system("pause");
}

void cargar(Biblioteca *pLibro, int max, Autor *pAutor){
    int i;
    int aux_i;      /*   AQUI GUARDARE LA PRIMERA POSICION VAICA DEL LIBRO, EN DONDE SE GUARDARA   */
    for (i=0;i<max;i++){        /*   MAX LIBRO   */
        if(pLibro[i].disponible == -1){
        /*************************** INSERTAR LIBRO ********************************/
        aux_i = i;      /*      LE COPIO EL VALOR A AUX_I PARA AL FINAL MOSTRAR LOS DATOS DE ESTA POSICION      */
        printf("  -  Libro: %d  - \n", i);
        pLibro[i].isbm = 100+i;     /*    SE INSERTA UN ISBN AUTOMATICO  */
        pLibro[i].disponible = 1;   /*    CAMBIO LA DISPONIBILIDAD DE -1 a 1  */
        printf("Nombre \n");
        fflush(stdin);
        gets(pLibro[i].nombre);     /*    SE INSERTA EL NOMBRE DEL LIBRO  */
        printf("Edicion: \n");
        scanf("%d",&pLibro[i].edicion);    /*    SE INSERTA EL LA EDICION DEL LIBRO  */
        printf("Tipo:  \n");
        fflush(stdin);
        gets(pLibro[i].tipo);       /*    SE INSERTA EL TIPO DEL LIBRO  */
        printf("Editorial \n");
        fflush(stdin);
        gets(pLibro[i].editoral);   /*    SE INSERTA EL EDITORIAL DEL LIBRO  */

        /*************************** INSERTAR AUTORES ********************************/
        system ("cls");

        int item;   /*   item SERA LA VARIABLE SINONIMO DE OPCION PARA ENTRAR EL SUBMENU DE AUTOR (1, 2, 0)   */
        int salir = 1;
        int a = 0, b = 0, ve;

        int id_autor = 0;
        bool id_encontrado = true;
        bool autor_no_repetido = true;
        while(a<5){
                if(pLibro[aux_i].autores[a] == -1){      /*   i ES LA PRIMERA POSICION LIBRE DEL ARREGLO LIBRO[i]
                                                      a ES LA PRIMERA POSICION LIBRE DEL ARREGLO AUTORES, LIBRO->AUTORES[a]*/
                do{

                printf("  -  AUTOR: <%d/%d>  - \n", a+1,5);  /*    */
                printf("1 - CARGAR NUEVO AUTOR\n");

                ve = existeAutorVacio(pAutor,max);          /*   OBETENER LA PRIMERA POSICION VACIA DEL ARREGLO AUTORES  */
                bool existeA = existeAutor(pAutor,max);     /*   SERA TRUE SI EXISTE UN AUTOR CARGADO EN EL ARREGLO AUTORES[MAX]     */

                /*   ESTA OPCION IF' SE DEBE MOSTRAR SOLO SI EXITE UN AUTOR COMO MINIMO   */
                /*   CASO CONTRARIO SE OMITIRIA PARA EL USUARIO                       */

                if(existeA){  /*   ENTRARA EN EL IF ES TRUE  */
                printf("2 - CARGAR AUTOR EXISTENTE\n");
                }
                printf("0 - SALIR\n");

                    scanf("%d",&item);

                    switch(item){
                    case 1:

                        pAutor[ve].id = ve;                 /*  INSERTAD ID AUTOMATICO  */
                        printf(" - DNI - :  \n");
                        scanf("%d",&pAutor[ve].dni);        /*  SE INGRESA EL DNI  */

                        printf(" - NOMBRE - :  \n");
                        fflush(stdin);
                        gets(pAutor[ve].nombre);            /*  SE INGRESA EL NOMBRE  */

                        printf(" - APELLIDO - :  \n");
                        fflush(stdin);
                        gets(pAutor[ve].apellido);          /*  SE INGRESA EL APELLIDO  */

                        printf(" - NACIONALIDAD - :  \n");
                        fflush(stdin);
                        gets(pAutor[ve].nacionalidad);      /*  SE INGRESA LA NACIONALIDAD  */

                        pLibro[aux_i].autores[a] = pAutor[ve].id;   /*  SE INSERTA EL ID DEL AUTOR DENTRO DEL ARREGLO LIBRO->AUTORES[I]  */

                        salir = 1;
                        a++;
                        break;
                    case 2:

                        printf("ESCOJA UN AUTOR A INSERTAR EN EL LIBRO\n");
                        mostrarAutores(pAutor,max);
                        do{
                            scanf("%d",&id_autor);
                            for(b = 0; b<5;b++){
                                if(pLibro[i].autores[b]==id_autor){     /*   RECORRO PARA VER SI ESTE AUTOR YA EXISTE EN EL ARREGLO LIBRO->AUTORES   */
                                    autor_no_repetido = false;          /*   SI EXISTE, ENTONCES AUTOR_NO_REPETIDO ES FALSO   */
                                    id_encontrado = false;
                                }
                            }


                            if(buscarIDtoAutorID(pAutor, max, id_autor)){   /*   SI SE ENCUENTRA EL ID DEVUELVE TRUE Y ENTRA EN EL ID   */
                                                                            /*     PRIMERA POSICION i DEL ARREGLO LIBRO LIBRE
                                                                            a PRIMERA POSICION LIBRE DEL ARREGLO LIBRO->AUTORES[a]
                                                                            id_autor ID IGRESADO POR EL USUARIO Y QUE DESEA INSERTAR*/
                                                                            /*printf("AGREGADA!: %d [%d]\n",pLibro[i].autores[a],a);*/
                                                                            /*   VERIFICO QUE NO EL ID NO ESTE REPETIDO   */

                            if(autor_no_repetido){
                                pLibro[i].autores[a] = id_autor;
                                id_encontrado = false;
                                printf("AUTOR AGREGADO!\n");
                                salir = 0;
                                a++;
                            }else{
                                printf("AUTOR YA EXISTENTE . NO PUEDE ESTAR EL MISMO AUTOR MAS DE UNA VEZ\n");
                                salir = 0;
                                system("pause");
                                break;
                            }
                            }else{
                                printf("ERROR ERROR ERROR\n");
                            }
                        }while(id_encontrado);   /*  SI ES TRUE SEGUIRA EN LA ITERACION, SIGNIFICA QUE AUN NO SE A INSERTADO EL ID   */

                        system ("cls");
                        break;
                    default:
                        break;

                    };
                if(item==0){
                    a = 5;      /*SALIR DEL WHILE DE a<5*/
                }
            }while(item!=0);


            }   /*  FIN PRIMER ESPACIO DISPONIBLE DENTRO DE LIBRO->AUTORES*/


            }   /* FIN DEL WHILE QUE RECORRER LOS 5 ESPACIOS DE AUTORES DENTRO DE LIBRO*/
            /*printf("aux:I %d\n", aux_i);*/
            mostrarLibro(pLibro,max,pAutor,aux_i);
            system("pause");
            break;
        } /*FIN DEL IF, PRIMER ESPACIO DISPONIBLE*/
         /*   FINALIZAR CARGADO DEL LIBRO    */
} /* FIN DEL FOR */
} /* FIN DEL VOID*/

void buscar(Biblioteca *pLibro, int max){


    int opcion;
    do{
        printf("*****    MENU DE BUSQUEDA    *****\n");
        printf("  1 - BUSCAR POR NOMBRE\n");
        printf("  2 - BUSCAR POR ISBN\n");
        printf("  3 - BUSCAR POR EDITORIAL\n");
        printf("  4 - BUSCAR POR TIPO\n");
        printf("  5 - BUSCAR POR EDICION\n");
        printf("  0 - SALIR\n");
        scanf("%d", &opcion);
        if(opcion >0 && opcion<6){
           buscarLibro(pLibro,max,opcion);
        }
        if((opcion <=0 || opcion>=6) && opcion!=0){
            printf("ERROR, VUELVA A INTENTARLO\n");

        }
        system("cls");

    }while(opcion !=0);

}

void busquedaIBSM(Biblioteca *pLibro,int max,int ibsm, Prestamo *prestar, int j){
    int i;
    for(i = 0; i<max; i++){
        if(pLibro[i].isbm == ibsm ){ /*VERIFICO QUE EL IBSM QUE ESCRIBI EXISTA EN EL ARREGLO pLibro*/

        }
    }
}

void buscarLibro(Biblioteca *pLibro,int max, int opcion){
        int i;
        char buscar[20];        /*     BUSCAR SERVIRA COMO CLAVE DE BUSQUEDA DE CADENA DE CARACTERES    */
        int clave;              /*     BUSCAR SERVIRA COMO CLAVE DE BUSQUEDA DE ENTEROS    */
        bool noEncontrado = true;    /*   BOOLEANO INICIADO PARA LLEVAR LA BANDERA' SI SE ENCONTRO LA CLAVE    */
        switch(opcion){
        case 1:
            printf("Nombre del Libro que va abuscar: \n");
            fflush(stdin);
            gets(buscar);
            for(i = 0; i<max;i++){       /*   RECORRE EL LARGO DEL ARREGLO LIBRO   */
                if(comparaStr(pLibro[i].nombre,buscar)){
                    printf("***  LIBRO ENCONTRADO!  ***\n");
                    printf(" - NOMBRE DEL LIBRO:  %s\n", pLibro[i].nombre);
                    printf(" - EDICION DEL LIBRO:  %d\n", pLibro[i].edicion);
                    printf(" - TIPO DEL LIBRO:  %s\n", pLibro[i].tipo);
                    printf(" - EDITORIAL DEL LIBRO:  %s\n", pLibro[i].editoral);
                    noEncontrado = false;
                }
            }
            if(noEncontrado){   /*   SI EL BOOLEANO NO ENTRA AL IF ANTERIOR SIGNIFICA QUE NO ENCONTRO LA CLAVE "BUSCAR" Y EL BOOLEANO
                                       TIENE EL VALOR TRUE DEL INICIO, SIGNIFICA QUE ENTRARA EN ESTE IF Y MOSTRARA EL SIGUIENTE MENSAJE */
                printf("NO SE ENCONTRO LA CLAVE INGRESADA \n");

            }
            system("pause");
            break;
        case 2:
            printf("ISBN DEL LIBRO QUE VA A BUSCAR: \n");
            scanf("%d",&clave);
            for(i = 0; i<max;i++){
                if(pLibro[i].isbm == clave){
                    printf("***  LIBRO ENCONTRADO!  ***\n");
                    printf(" - ISBN DEL LIBRO:  %d\n", pLibro[i].isbm);
                    printf(" - NOMBRE DEL LIBRO:  %s\n", pLibro[i].nombre);
                    printf(" - EDICION DEL LIBRO:  %d\n", pLibro[i].edicion);
                    printf(" - TIPO DEL LIBRO:  %s\n", pLibro[i].tipo);
                    printf(" - EDITORIAL DEL LIBRO:  %s\n", pLibro[i].editoral);
                    noEncontrado = false;
                }
            }
            if(noEncontrado){
                printf("NO SE ENCONTRO LA CLAVE INGRESADA \n");
            }
            system("pause");
            break;
        case 3:
            printf("EDITORIAL DEL LIBRO QUE VA A BUSCAR: \n");
            fflush(stdin);
            gets(buscar);
            for(i = 0; i<max;i++){
                if(comparaStr(pLibro[i].editoral,buscar)){
                    printf("***  LIBRO ENCONTRADO!  ***\n");
                    printf(" - NOMBRE DEL LIBRO:  %s\n", pLibro[i].nombre);
                    printf(" - EDICION DEL LIBRO:  %d\n", pLibro[i].edicion);
                    printf(" - TIPO DEL LIBRO:  %s\n", pLibro[i].tipo);
                    printf(" - EDITORIAL DEL LIBRO:  %s\n", pLibro[i].editoral);
                    noEncontrado = false;
                }
            }
            if(noEncontrado){
                printf("NO SE ENCONTRO LA CLAVE INGRESADA \n");
            }
            system("pause");
            break;
        case 4:
            printf("TIPO DEL LIBRO QUE VA A BUSCAR: \n");
            fflush(stdin);
            gets(buscar);
            for(i = 0; i<max;i++){
                if(comparaStr(pLibro[i].tipo,buscar)){
                    printf("***  LIBRO ENCONTRADO!  ***\n");
                    printf(" - NOMBRE DEL LIBRO:  %s\n", pLibro[i].nombre);
                    printf(" - EDICION DEL LIBRO:  %d\n", pLibro[i].edicion);
                    printf(" - TIPO DEL LIBRO:  %s\n", pLibro[i].tipo);
                    printf(" - EDITORIAL DEL LIBRO:  %s\n", pLibro[i].editoral);
                    noEncontrado = false;
                }
            }
            if(noEncontrado){
                printf("NO SE ENCONTRO LA CLAVE INGRESADA \n");
            }
            system("pause");
            break;
        case 5:
            printf("EDICION DEL LIBRO QUE VA A BUSCAR: \n");
            scanf("%d",&clave);
            for(i = 0; i<max;i++){
                if(pLibro[i].edicion==clave && clave !=0 && clave !=-1){        /*   DISTINTO DE -1 Y 0 PARA EVITAR QUE MUESTRE LOS ELEMENTOS VACIOS   */
                    printf("***  LIBRO ENCONTRADO!  ***\n");
                    printf(" - NOMBRE DEL LIBRO:  %s\n", pLibro[i].nombre);
                    printf(" - EDICION DEL LIBRO:  %d\n", pLibro[i].edicion);
                    printf(" - TIPO DEL LIBRO:  %s\n", pLibro[i].tipo);
                    printf(" - EDITORIAL DEL LIBRO:  %s\n", pLibro[i].editoral);
                    noEncontrado = false;
                }
            }
            if(noEncontrado){
                printf("NO SE ENCONTRO LA CLAVE INGRESADA \n");
            }
            system("pause");
            break;

    };
}

void darBaja(Biblioteca *pLibro,int max){

    printf("**** INGRESE EL ISBN DEL LIBRO A DAR DE BAJA    ****\n");
    int a,b;
    do{
        scanf("%d",&a);
        if(!estaVacio(pLibro,max,a)){
              b = idLibroTOposicionLibro(pLibro,max,a);
              printf("SE ENCONTRO EL LIBRO: %s \n",pLibro[b].nombre);
              vaciar(pLibro, b);
              if(pLibro[b].disponible == -1){
                printf("BORRADO!\n");
              }

        a = 0;
        system("pause");
        }else{
            printf("NO EXISTE EL LIBRO, INTENTELO DE NUEVO\n");
        }

    }while(a != 0);
}

void mostrarLista(Biblioteca *pLibro,int max){
    int i;
    for (i = 0; i<max;i++){
        if(pLibro[i].disponible!=-1){
           printf("%d - %s | ISBM : %d | \n",i,pLibro[i].nombre, pLibro[i].isbm);
        }

    }

}

void mostrar(Biblioteca *pLibro, int posicion){
        printf("\n      [ DATOS DEL LIBRO ]\n");
        printf("     POSICION: %d \n", posicion);
        printf("     NOMBRE: %s \n", pLibro[posicion].nombre);
        printf("     EDICION: %d \n", pLibro[posicion].edicion);
        printf("     TIPO: %s \n", pLibro[posicion].tipo);
        printf("     EDITORIAL: %s \n", pLibro[posicion].editoral);
        printf("     CANTIDAD: %d \n", pLibro[posicion].cantidad);
        int i;
}

void modificarDato(Biblioteca *pLibro,int max, Autor *pAutor){
    int op,op2,op3, salir = 0, salir2 = 0, salir3= 0;   /*SALIR, PARA SALIR DE LOS WHILE*/
    int a;               /*para los for*/
    int b;          /*VARIABLE PARA EL SUB MENU DE INSERTAR AUTORES*/
    int c,d;        /*   PARA LECTURAS DE SCANF   */

    printf("****   INGRESE EL ISBN DEL LIBRO A MODIFICAR   ****\n");
    mostrarLista(pLibro,max);
    do{
        scanf("%d",&op);        /*   op GUARDA EL ISBN INGRESADO POR EL USUARIO   */
        if(!estaVacio(pLibro,max,op)){      /*   estaVacio DEBE RETORNAR CON EL VALOR FALSE SI EXISTE EL
                                            ISBN EN EL ARREGLO LIBROS, SIN EMBARGO PORNEMOS EL SIGNO ' ! '
                                            PARA QUE ENTRE EL IF. (!) SIGNFICA: LA FUNCION RETORNA UN VALOR DISTINTO A VERDADERO?
                                            SI, RETORNA UN FALSE, ENTONCES ENTRA EN EL IF
                                            */
            int v = idLibroTOposicionLibro(pLibro,max,op);  /*   POR MEDIO DEL ISBN/ID RETORNO LA POSICION DEL LIBRO   */

            /*   PREGUNTO EL ATRIBUTO   */

            do{
                    /*  op2 VARIABLE PARA EL MENU DE MODIFICAR Y ACCEDER A UNA OPCION  */
                bool noExiste = true; /*     PARA MOSTRAR MENSAJES DE QUE NO EXISTE.    */
                printf("*****    QUE DATO QUIERE MODIFICAR    *****\n");
                printf("              -  - LIBRO - - \n");
                printf("1 - NOMBRE DEL LIBRO\n");
                printf("2 - EDICION DEL LIBRO\n");
                printf("3 - TIPO DEL LIBRO\n");
                printf("4 - EDITORIAL DEL LIBRO\n");
                printf("5 - CANTIDAD DE LIBROS\n");
                printf("              -  - AUTOR - - \n");
                printf("6 - EL AUTOR \n");
                printf("0 - SALIR\n");
                scanf("%d", &op2);

                switch(op2){
                case 1:
                    printf (" USTED VA A CAMBIAR  EL NOMBRE : %s \n",pLibro[v].nombre);
                    fflush(stdin);
                    gets(pLibro[v].nombre);
                    printf(" NOMBRE ACTUALIZADO : %s\n",pLibro[v].nombre);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    system("pause");
                    break;
                case 2:
                    printf (" USTED VA A CAMBIAR  LA EDICION : %d \n",pLibro[v].edicion);
                    scanf("%d",&pLibro[v].edicion);
                    printf(" EDICION ACTUALIZADO : %d\n",pLibro[v].edicion);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    system("pause");
                    break;
                case 3:
                    printf (" USTED VA A CAMBIAR  EL TIPO DE LIBRO : %s \n",pLibro[v].tipo);
                    fflush(stdin);
                    gets(pLibro[v].tipo);
                    printf(" TIPO ACTUALIZADO : %s\n",pLibro[v].tipo);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    system("pause");
                    break;
                case 4:
                    printf (" USTED VA A CAMBIAR  EL EDITORIAL : %s \n",pLibro[v].editoral);
                    fflush(stdin);
                    gets(pLibro[v].editoral);
                    printf(" EDITORIAL ACTUALIZADO : %s\n",pLibro[v].editoral);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    system("pause");
                    break;
                case 5:
                    printf (" USTED VA A CAMBIAR  LA CANTIDAD : %d \n",pLibro[v].cantidad);
                    scanf("%d",&pLibro[v].cantidad);
                    printf(" CANTIDAD ACTUALIZADO : %d\n",pLibro[v].cantidad);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    printf("\n");
                    printf (" ***     SUB MENU PARA MODIFICAR EL AUTOR DEL LIBRO      ***\n");
                    printf (" 1 - INSERTAR UN NUEVO AUTOR\n");
                    printf (" 2 - MODIFICAR UN AUTOR\n");
                    printf (" 3 - ELIMINAR UN AUTOR\n");
                    printf (" 0 - SALIR\n");
                    do{
                        /*   op3    PARA EL SUB MENU DE AUTORES A MODIFICAR   */
                        scanf("%d",&op3);
                        switch(op3){
                        case 1:
                            for(a=0;a<5;a++){       /*v SIGUE SIENDO LA POSICION EN DONDE SE ENCUENTRA EL ISBN CONSULTADO ARRIBA*/
                                if(pLibro[v].autores[a] == -1){
                                    printf("POSICION DISPONIBLE : %d\n",a);
                                    printf("INSERTE EL ID DEL AUTOR PARA AGREGAR : %d\n",a);

                                    do{
                                    scanf("%d",&b);
                                    if(buscarIDtoAutorID(pAutor,max,b)){   /*   FUNCION: VERIFICO SI EL ID EXISTE EN EL ARREGLO DE AUTORES->ID SI EXISTE DEVUELVE TRUE Y ENTRA EN EL IF  */
                                        pLibro[v].autores[a] = b;       /*   INSERTO EN LA PRIMERA POSICION LIBRO DE LIBRO->AUTORE[a] EL ID INGRESADO POR EL USUARIO b   */
                                        salir2 = 1;
                                    }

                                    }while(salir2 ==0);



                                    noExiste = false;       /* SI ENTRO EN EL IF SIGNIFICA QUE EXISTE UN ESPACIO DISPONIBLE EN LIBRO->AUTORES
                                                               ENTONCES LO CAMBIO A FALSE PARA QUE NO ENTRE EN EL MENSAJE DE ABAJO*/
                                break;      /*UNA VEZ AGREGADO UN AUTOR SALIRMOS DEL CICLO FOR*/
                                }

                            }
                            if(noExiste){
                                printf("NO EXISTE ESPACIO PARA INSERTAR UN NUEVO LIBRO");
                            }
                            mostrarLibro(pLibro,max,pAutor,v);      /*   MOSTRAR TODOS LOS DATOS LIBRO DONDE TRABAJAMOS, POSICION v   */
                            system("pause");
                            op3 = 0; /*  CAMBIAR A 0 PARA SALIR DEL WHILE YA QUE TERMINAMOS DE INSERTAR*/
                            break;

                        case 2:
                            /*   PRIMERO MOSTRAR ID DE AUTORES DEL LIBRO   */
                            printf("\nESCOJA UNA OPCION PARA MODIFICAR\n");
                            for(a = 0; a<5;a++){
                                if(pLibro[v].autores[a]!= -1){  /*   SI ES DISTINTO DE -1 ENTONCES EXISTE UN AUTOR Y  LO MUESTRO   */
                                    int k = idAutorTOposicionAutor(pAutor,max,pLibro[v].autores[a]);        /*  ENVIO EL ID DEL AUTOR Y ME DEVUELVE LA POSICION DONDE SE ENCUENTRA EN EL ARREGLO AUTORES, Y LA GUARDO EN LA K  */
                                    printf(" %d - Autor %s : ID %d\n",a,pAutor[k].nombre,pLibro[v].autores[a]); /*  USO LA K (POSICION) Y OBTENGO LOS DATOS DEL AUTOR EN ESA POSICION, EN ESTE CASO LO EL NOMBRE    */
                                }
                            }

                            /*    PRIMER DO WHILE PARA VERIFICAR QUE ESCOJA BIEN LA POSICION DE LIBRO->AUTORES[a]  */
                            do{
                                scanf("%d",&c);
                                if(pLibro[v].autores[c]!=-1){   /*   LIBRO->AUTORES[C] ES DISTINTO DE VACIO? ENTRA EN EL IF   */
                                        printf("INSERTE EL ID DE UN NUEVO AUTOR | ID ACTUAL : %d\n",pLibro[v].autores[c]);
                                        do{ /*   PARA VERIFICAR QUE EL NUEVO ID EXISTA EN EL ARREGLO DE LOS AUTORES   */
                                            scanf("%d",&d);     /*   d NUEVO ID QUE REEMPLAZAR AL ANTERIOR   */
                                            if(buscarIDtoAutorID(pAutor,max,d)){       /*   SI EL ID DEL AUTOR EXISTE EN EL ARREGLO AUTORES ENTONCES LO INSERTAMOS   */
                                                pLibro[v].autores[c] = d;       /*   LO REEMPLAZAMOS   */
                                                printf("EL VALOR FUE ACTUALIZADO A : %d\n",pLibro[v].autores[c]);
                                                salir3 = 1;     /*   CON ESTO SALIMOS DEL WHILE. UNA VEZ ACTUALIZADO EL DATO   */
                                            }else{
                                                printf("NO EXISTE UN AUTOR CON ESA ID, INTENTELO NUEVAMENTE\n");
                                            }

                                        }while(salir3 == 0);
                                    salir2 = 1; /*   CON ESTO SALIMOS DEL WHILE. UNA VEZ TERMINADO EL IF   */
                                }else{
                                    printf("EL VALO INGRESADO ES INVALIDO POR QUE NO EXISTE UN AUTOR EN ESA POSICION\n");
                                }
                            }while(salir2 ==0 );
                            mostrarLibro(pLibro,max,pAutor,v);
                            system("pause");
                            op3 = 0;
                            break;
                        case 3:
                            /*   PRIMERO MOSTRAR ID DE AUTORES DEL LIBRO   */
                            for(a = 0; a<5;a++){
                                if(pLibro[v].autores[a]!= -1){  /*   SI ES DISTINTO DE -1 ENTONCES EXISTE UN AUTOR Y  LO MUESTRO   */
                                    int k = idAutorTOposicionAutor(pAutor,max,pLibro[v].autores[a]);
                                    printf(" %d - Autor %s : ID %d\n",a,pAutor[k].nombre,pLibro[v].autores[a]);
                                }
                            }
                            printf("\nESCOJA UNA OPCION PARA BORRAR\n");
                            do{
                                scanf("%d",&c);
                                if(pLibro[v].autores[c]!=-1){   /*   LIBRO->AUTORES[C] ES DISTINTO DE VACIO? ENTRA EN EL IF   */
                                    pLibro[v].autores[c] = -1;
                                    if(pLibro[v].autores[c] == -1){
                                        printf("UNO DE LOS AUTORES DEL LIBRO FUE BORRADO\n");
                                        salir2 = 1;
                                    }
                                }else{
                                    printf("EL VALO INGRESADO ES INVALIDO POR QUE NO EXISTE UN AUTOR EN ESA POSICION\n");
                                }
                            }while(salir2 ==0 );
                            mostrarLibro(pLibro,max,pAutor,v);
                            system("pause");
                            op3 = 0;
                            break;
                        };

                    }while(op3!=0);
                    mostrar(pLibro,idLibroTOposicionLibro(pLibro,max,op));
                    break;
                };
                system("cls");
            }while(op2!=0);


            salir = 1; /*    PARA SALIR DEL CICLO WHILE UNA VEZ MODIFICADO EL VALOR   */

        }else{
            printf("NO SE ENCONTRO, INTENTELO NUEVAMENTE\n");
        }
    }while(salir == 0);
}

/***************** MENU ********************/

void menu(Biblioteca *pLibro, int max, Persona *usuario, Prestamo *pPrestar, Autor *pAutor){
    int opcion = 1,continuar = 0;
    int j,k;
    bool noHayPrestamos = true;
    do{
    printf("*****     MENU DE OPCIONES     *****\n");
    printf("        1 - CARGAR LIBRO\n");
    printf("        2 - BUSCAR LIBRO\n");
    printf("        3 - DAR DE BAJA LIBRO\n");
    printf("        4 - PEDIR LIBRO PRESTADO\n");
    printf("        5 - DEVOLUCION DEL LIBRO PRESTADO\n");
    printf("        6 - MODIFICAR UN ATRIBUTO DEL LIBRO\n");
    printf("        7 - MOSTRAR LIBRO\n");
    printf("        0 - SALIR\n");

    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            cargar(pLibro,max,pAutor);
            break;
        case 2:
            buscar(pLibro,max);
            break;
        case 3:
            /* el 3 es la opcion de DAR DE BAJA para que la funcion sepa que hacer*/
            darBaja(pLibro,max);
            break;
        case 4:
            prestamoLibro(pLibro,max,usuario,pPrestar);
            break;
        case 5:
            for(k = 0;k<3;k++){
                if(usuario->prestamos[k]!=-1){
                    devolucion(pLibro,max,usuario, pPrestar);
                    noHayPrestamos = false;
                }
            }
            if(noHayPrestamos){
                printf("NO HAY PRESTAMOS ACTIVOS PARA ESTE USUARIO\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            modificarDato(pLibro,max,pAutor);
            break;
        case 7:
            mostrarFuncionFinal(pLibro, max, pAutor);
            break;
    };
        /*printf ("\nOPRIMA 1 SI DESEA CONTINUAR \n");
        scanf ("%d", &continuar);*/
        system ("cls");
    }while(opcion!=0);
}

/***************** MAIN ********************/

int main()
{
    /***** LIBRO STRUC ****/

    int max = 10;
    Biblioteca Libro[max];
    Biblioteca *pLibro;
    pLibro = &Libro;
    inicializarStruc(pLibro,max);
    cargarLibro(pLibro,max);    /*  CARGAR UN LIBRP DE PRUEBA  posicion 5 */

    /***** PERSONA STRUC ****/

    Persona usuario;
    Persona *pUsuario;
    pUsuario = &usuario;

    usuario.dni = 38060112;
    usuario.multa = 0;
    usuario.nombre[0] = 'F';
    usuario.nombre[1] = 'e';
    usuario.nombre[2] = 'r';
    usuario.prestamos[0] = -1;
    usuario.prestamos[1] = -1;
    usuario.prestamos[2] = -1;

    /***** PRESTAMOS STRUC ****/

    Prestamo prestar[max];
    Prestamo *pPrestar;
    pPrestar = &prestar;
    iniciarPrestamos(pPrestar,max);

    /***** AUTOR STRUC ****/

    Autor autor[max];
    Autor *pAutor;
    pAutor = &autor;
    iniciarAutores(pAutor,max);
    preCargarAutores(pAutor);   /*   CARGAR DOS AUTORES DE PRUEBA   */

    /*****     MAIN    ****/

    menu(pLibro, max, pUsuario,pPrestar, pAutor);

    return 0;
}