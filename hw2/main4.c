#include <stdio.h>

typedef struct{
    int id;
    int price;
    char title [50];
}Book;

void total_price(Book books[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum +=books[i].price;
    }
    printf("%d\n",sum);
}

void list_books(Book books[],int index){
    printf("%d %s\n",books[index].price,books[index].title);
}

int main()
{
    Book books[6] ={
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Balland of Soongbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };
    
    int input;
    scanf("%d",&input);
    
    if(input == 0){
        total_price(books,6);
    }else if(input>=1 && input<=6){
        list_books(books,input -1);
    }

    return 0;
}
