#include "lista.h" 

struct lista_{
    ITEM *list[maxn] ;
    int ini, fim ; 
} ;

LISTA *criar(){

    LISTA *a = (LISTA *) malloc(sizeof(LISTA)) ;
    
    if(a != NULL) a -> ini = 0, a -> fim = 0 ; 

    return a ; 

}

int busca(LISTA *lista, int a){ // achar o 1o elemento q tem valor >=a - onde irei colocar p manter a ordem 

    // busca binaria - O(log(n))

    int ini = lista -> ini, fim = lista->fim - 1, mid, best = -1 ; 

    while(ini <= fim){

        mid = (ini + fim)>>1 ;

        if(item_get_chave(lista->list[mid]) >= a) best = mid, fim = mid - 1 ; 
        else ini = mid + 1 ; 

    }

    return best ; 

}

void lista_apagar(LISTA **lista){ // percorre tudo e aponta cada kra p null e da free nele depois da free na lista 
    
    if((*lista) != NULL){

        for(int i = (*lista)->ini ; i < (*lista)->fim ; i++){
            item_apagar(&((*lista)->lista[i])) ; 
        }

        free(*lista) ; 
        *lista = NULL ; 

    }

}

bool lista_inserir(LISTA *lista, ITEM *a){ // insere em pos - O(N)
    
    int pos = busca(lista, item_get_chave(a)) ;

    if(pos == -1) pos = lista->fim ; 

    if(lista != NULL && !lista_cheia(lista) && pos <= lista -> fim){
        for(int i = lista-> fim - 1 ; i >= pos ; i--){
            lista -> list[i+1] = lista -> list[i] ;
        }
        lista->list[pos] = a ; 
        lista->fim++ ; 
        return 1 ; 
    }
    
    return 0 ; 

}

ITEM *lista_remove(LISTA *lista, ITEM *a){ // tira do começo 
    
    int pos = busca(lista, item_get_chave(a)) ;

    if(lista != NULL && !lista_vazia(lista) && pos >= lista->ini && pos <= lista->fim-1){
        ITEM *b = lista->list[pos] ;
        lista->list[pos] = NULL ; 
        for(int i = pos + 1 ; i < lista->fim; i++) lista->list[i-1] = lista->list[i] ;
        lista->fim-- ; 
        return b ;
    }

    return NULL ; 

}

int lista_tamanho(LISTA *a){ 
    if(a != NULL) return (a -> fim) - (a -> ini) ;
    return -1 ; 
}

bool lista_vazia(LISTA *a){ 
    if(a != NULL) return (a->fim == 0) ; 
    return 0 ; 
}

bool lista_cheia(LISTA *a){ 
    if(a != NULL) return lista_tamanho(a) == maxn ;
    return NULL ; 
}

void lista_imprime(LISTA *a){
    if(a == NULL) return ; 
    for(int i = a->ini ; i < a->fim ; i++) item_imprimir(a->list[i]) ; 
}

void lista_find(LISTA *list, ITEM *a){
    if(list == NULL || lista_vazia(list)){
        printf("Nao tem como achar") ;
        return ; 
    } 
    for(int i = list->ini ; i < list-> fim ; i++) {
        if(valor(list->list[i]) == valor(a)){
            printf("Tem esse valor %d", valor(list->list[i])) ; 
            return ; 
        }
    }
    printf("Nao tem esse valor\n") ;
}
    
