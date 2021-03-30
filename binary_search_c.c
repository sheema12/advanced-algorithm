#include<stdio.h>
#include<stdlib.h>
struct index    // creating a structure named index
{
   int key;
   struct index *left, *right;
};
struct index *Node1(int item)
{
   struct index *temp = (struct index *)malloc(sizeof(struct index));   //memory allocation using malloc
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}
void traversetree(struct index *root)
{
   if (root != NULL)
   {
      traversetree(root->left);
      printf("%d \t", root->key);
      traversetree(root->right);
   }
}
struct index* search(struct index* root, int key)   //searching
{
   if (root == NULL || root->key == key)
      return root;
   if (root->key < key)
      return search(root->right, key);
   return search(root->left, key);
}
struct index* insert(struct index* index, int key)   //inserting
{
  if (index == NULL)
    return Node1(key);
  if (key < index->key)
    index->left = insert(index->left, key);
  else if (key > index->key)
    index->right = insert(index->right, key);
  return index;
}
struct index *minValueNode(struct index *index) {
  struct index *current = index;


  while (current && current->left != NULL)
    current = current->left;

  return current;
}
struct index *deleteNode(struct index *root, int key) {   //deleting

  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {

    if (root->left == NULL) {
      struct index *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct index *temp = root->left;
      free(root);
      return temp;
    }


    struct index *temp = minValueNode(root->right);
    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
int main()
{
  printf("\nSheema Zainab MI 19MID0014\n");
  struct index
  *root = NULL;
  root = insert(root, 1);
  insert(root, 2);
  insert(root, 3);
  insert(root, 4);
  insert(root, 5);
  insert(root, 6);
  printf("The tree is :\n");
  traversetree(root);
  printf("\nEnter the number to be update \n");
  int u;
  scanf("%d",&u);
  insert(root, u);
  printf("After updating: is :\n");
  traversetree(root);
  printf("\n");
  printf("Enter the number to search \n");
  int s;
  scanf("%d",&s);
  if(search(root,s))
    printf("Node %d found\n",s);
  else
    printf("Node not found %d\n",s);
  printf("\nEnter the number to be deleted : \n");
  int d;
  scanf("%d",&d);
  root = deleteNode(root, d);
  printf("\nList after deleting : \n");
  traversetree(root);
  printf("\n");
  return 0;
}
