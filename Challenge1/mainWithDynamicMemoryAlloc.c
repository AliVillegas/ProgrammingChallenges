#include <stdio.h>
#include <stdlib.h>

struct Node {
   int  age;
   char *name; 
   struct Node * nextNode;
};

struct LinkedList{
   int size;
   struct Node * firstNode; 
};


//adds item to the end of the list
int addItem(struct LinkedList *l, struct Node *item){
   if(l->size == 0){
      l->firstNode = item;
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode = l->firstNode;
      indexNode->nextNode = NULL;
      l->size = l->size +1;
   }
   else if(l->size == 1){
     struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
     indexNode = l->firstNode;
     indexNode->nextNode = item;
     indexNode->nextNode->nextNode = NULL;
     l->size = l->size +1;
   }
   else{
     struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
     indexNode = l->firstNode;
     while(indexNode->nextNode != NULL){
          indexNode = indexNode->nextNode; 
      }
      indexNode->nextNode = item;
      struct Node *indexNode2 = (struct Node*) malloc(sizeof(struct Node));
      indexNode->nextNode->nextNode = NULL;
      l->size = l->size +1;
   } 
   return 0; 
}

//pushes an item in the first position of the list
int pushItem(struct LinkedList *l, struct Node *item){
   if(l->size == 0){
      l->firstNode = item;
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      indexNode->nextNode = NULL;
      l->size = l->size +1;
   }
   else{
     struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
     indexNode  = l->firstNode;
     l->firstNode = item;
     struct Node *indexNode2 = (struct Node*) malloc(sizeof(struct Node));
     indexNode2  = l->firstNode;
     indexNode2->nextNode = indexNode;
     l->size = l->size +1;
   } 
   return 0; 
}

//Prints the list
int printLinkedList(struct LinkedList *l){
  if(l->size== 0){
    printf("The list has no elements");
  }
  else if(l->size==1){
    int index = 0 ; 
    struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
    indexNode  = l->firstNode;
         printf("\n%d--Age: %d Name: %s", index, indexNode->age,indexNode->name);
    }
   else{
      int index = 0 ; 
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      while(indexNode->nextNode != NULL){
          printf("\n%d--Age: %d Name: %s", index, indexNode->age,indexNode->name);
          index++;
          indexNode = indexNode->nextNode; 
      }
      printf("\n%d--Age: %d Name: %s", index, indexNode->age,indexNode->name);
   }
  
  return 0; 
}

//Removes first item on the list
int popItem(struct LinkedList *l){
  if(l->size == 0){
     printf("There's nothing to pop");
  }
  else{
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      l->firstNode = NULL; 
      l->firstNode =  indexNode->nextNode;
      l->size = l->size - 1;
  }
  
  return 0; 
}

//Removes last item of the list
int removeLastItem(struct LinkedList *l){
   if(l->size== 0){
    printf("\nThe list already has no elements\n");
  }
  else if(l->size==1){
    l->firstNode = NULL; 
    l->size = l->size - 1;
    }
   else{
     struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      struct Node *previousNode = (struct Node*) malloc(sizeof(struct Node));
      previousNode = NULL; 
      while(indexNode->nextNode != NULL){
          previousNode = indexNode;
          indexNode = indexNode->nextNode; 
      }
      previousNode->nextNode = NULL; 
      indexNode = NULL; 
      l->size = l->size - 1;
   }
  
  return 0; 
}

//Removes the item on the given index 
int removeItem(struct LinkedList *l, int index){
  if(l->size== 0){
    printf("The list has no elements \n");
  }
  else if(l->size -1 < index){
    printf("The list doesn't have that index \n");
  }
  else if(index == 0 && l->size == 1){
    l->firstNode = NULL; 
    l->size = l->size - 1;
  }
  else if(index == 0){
    struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
    indexNode  = l->firstNode;
    l->firstNode = indexNode->nextNode; 
    indexNode = NULL; 
    l->size = l->size - 1;
  }
  else{
    if(index == l->size-1){
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      struct Node *previousNode = (struct Node*) malloc(sizeof(struct Node));
      previousNode  = NULL;
      while(indexNode->nextNode != NULL){
          previousNode = indexNode;
          indexNode = indexNode->nextNode;
          }
       previousNode->nextNode = NULL; 
       indexNode = NULL; 
      }
    else{
      int i = 0; 
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      struct Node *previousNode = (struct Node*) malloc(sizeof(struct Node));
      previousNode = NULL;
      while(indexNode->nextNode != NULL){
          previousNode = indexNode;
          indexNode = indexNode->nextNode;
          i++; 
          if(i == index){
            break;
          }
        }
       previousNode->nextNode = indexNode->nextNode; 
       indexNode = NULL; 
      }
    }
  return 0; 
}

//Returns the size of the list
int getSize(struct LinkedList *l){
  printf("The size of the list is: %d\n", l->size);
  return 0;
}

//Retrieves the node on a given index
int getItem(struct LinkedList *l){
  int n;
  printf("\nType the index you want to retrieve: ");
  scanf("%d", &n);
  if(l->size== 0){
    printf("The list has no elements \n");
  }
  if(l->size -1 < n){
    printf("The list doesn't have that index \n");
  }
  else if(l->size==1 && n == 0){
    int index = 0; 
    struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
    indexNode  = l->firstNode;
         printf("\n%d--Age: %d Name: %s \n", index, indexNode->age,indexNode->name);
    }
    else {
      int index = 0 ; 
      struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
      indexNode  = l->firstNode;
      if(n == 0) {
        printf("\n%d--Age: %d Name: %s \n", index, indexNode->age,indexNode->name);
        return 0;
      }
      while(indexNode->nextNode != NULL){
          index++;
          indexNode = indexNode->nextNode;
          if(index == n) {
            printf("\n%d--Age: %d Name: %s \n", index, indexNode->age,indexNode->name);
            return 0;
          }
      }
    }
  return 0; 
}

//Deletes every node on the list
int clearList(struct LinkedList *l){
  if(l->size == 0)
    printf("List has no elements to clear");
  else if(l->size == 1){
    l->firstNode = NULL;
  }
  else{
    struct Node *indexNode = (struct Node*) malloc(sizeof(struct Node));
    indexNode = l->firstNode;
    struct Node *previousNode = (struct Node*) malloc(sizeof(struct Node));
    previousNode = NULL;
    while(indexNode->nextNode != NULL){
      previousNode = indexNode;
      indexNode = indexNode->nextNode; 
      previousNode->nextNode = NULL;
      previousNode = NULL;
    }
    l->firstNode = NULL;
    l->size = 0;
  }
  return 0; 
}



int main(void) {
  //linked list implementation using structures
  struct Node *items = (struct Node*) calloc(5,sizeof(struct Node));
  struct Node item1; 
  struct Node item2;
  struct Node item3;
  struct Node item4;
  struct Node item5;
  items[0] = item1;
  items[1] = item2;
  items[2] = item3;
  items[3] = item4;
  items[4] = item5;
  item1.age = 15; 
  item1.name= "Malcolm";
  item2.age = 20; 
  item2.name = "Felicity"; 
  item3.age = 13; 
  item3.name = "Julius"; 
  item4.age = 69; 
  item4.name = "Clark";
  item5.age = 18; 
  item5.name = "Travolta"; 
  struct LinkedList *linkedList = (struct LinkedList*) calloc(1,sizeof(struct LinkedList));
  struct LinkedList list; 
  linkedList[0] = list; 
  list.size = 0;
  addItem(&list, &item1);
  addItem(&list, &item2);
  addItem(&list, &item3);;
  getSize(&list);
  printf("Printing List after filling:\n");
  printLinkedList(&list);
  getItem(&list);
  free(items);
  free(linkedList);

  return 0;
}
