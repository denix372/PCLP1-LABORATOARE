#include "mapst.h"
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct entry {
   void * key;
   void * value;
} entry;
 
typedef struct map {
   entry ** elem; // vectorul de elemente; este alocat si realocat dinamic
   int n_elem; // numarul de elemente din vector
   int cap; // capacitatea vectorului
} map;
*/

void init(map *m, int cap)
{
    m->elem = (entry**)calloc(cap, sizeof(entry*));
    m->n_elem = 0;
    m->cap = cap;
}

void print(map* m, void (*printEntry) (const entry*))
{
    int i;
    for (i = 0;i < m->n_elem;i++) {
        printEntry(m->elem[i]);
    }
}

void add(map* m, entry* e)
{
    entry** ptr_aux;
    if (m->n_elem == m->cap) {
        m->cap += CAP_STEP;
        ptr_aux = (entry**)realloc(m->elem, m->cap*sizeof(entry *));//gbt
        if (ptr_aux != NULL) {
            m->elem = ptr_aux;
        }
    }
    m->elem[m->n_elem] = e;
    m->n_elem++;
}

void sort(map* m, int (*fc) (const void*, const void*))
{
    qsort(m->elem, m->n_elem, sizeof(entry*), fc);
}

void del(map *m, void *k, int (*fc2)(const void *, const void *)) { 
    int i, j;
    for (i = 0; i < m->n_elem;i++)
        if(fc2(k, m->elem[i]->key)==0)
        {
          for (j = i; j < m->n_elem - 1; j++) 
            m->elem[j]= m->elem[j+1];
          m->n_elem--;
        }
}

// functie ce întoarce valoarea asociata unei chei. Se va folosi functia bsearch! Observatie: fc va trebui sa compare între ele 2 structuri entry* (se va face conversie la entry ** in functia de comparatie!! DE CE?). Vectorul tb sortat in prealabil! Dar, atentie el nu tb sa iasa modificat, se va lucra pe o copie a lui!
void *find(map *m, void *k, int ( * fc ) ( const void *, const void * )){
  map t;
  entry **p;
  t = clone_map(m);
  
  sort(&t, fc);
  p = (entry **)bsearch(&k, t.elem, t.n_elem, sizeof(entry *), fc);
  if (p == NULL) return NULL;
  return (*p)->value;
}

// functie care imi cloneaza dictionarul (pentru a fi folosit in find)
map clone_map(const map *m) { 
    map t;
    int i;
    t.cap = m->cap;
    init(&t, t.cap);
    t.n_elem = m->n_elem;
    for (i = 0;i < m->n_elem;i++) {
        t.elem[i] = malloc(sizeof(entry));
        t.elem[i]->key = strdup((char*)m->elem[i]->key);
        t.elem[i]->value = strdup((char*)m->elem[i]->value);
    }
    return t;
}
