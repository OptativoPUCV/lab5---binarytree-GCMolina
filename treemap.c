#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    TreeMap * map=(TreeMap*)malloc(sizeof(TreeMap));
    map->root=NULL;
    map->current=NULL;
    map->lower_than = lower_than;
    return map;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    TreeNode* New=createTreeNode(key,value);
    if(tree->root==NULL){
      tree->root = New;
      tree->current=New;
    }else{
      tree->current=tree->root;
    }
    while(tree->current!=NULL){
      if(is_equal(tree,key,tree->current->pair->key)){
        return;
      }
      if(tree->lower_than(key,tree->current->pair->key)==1){
        if(tree->current->left==NULL){
          tree->current->left=New;
          New->parent=tree->current;
        }
        tree->current=tree->current->left;
      }
      else{
        if(tree->current->right==NULL){
          tree->current->right = New;
          New->parent=tree->current;
        }
        tree->current=tree->current->right;
      }
        
        
        
      }
  }

TreeNode * minimum(TreeNode * x){
  while(x->left!=NULL){
    x=x->left;
  }
    return x;
}


void removeNode(TreeMap * tree, TreeNode* node) {
if (node->left==NULL&&node->right==NULL){
  if(node->parent!=NULL){
    if(node==node->parent->left){
      node->parent->left=NULL;
    }else{
      node->parent->right=NULL;
    }
    
  }
  else{
    tree->root=NULL;
  }
  free(node);
}else if((node->left==NULL&&node->right!=NULL)||(node->left!=NULL && node->right==NULL)){
  if(node->parent!=NULL){
    if(node->left==NULL&&node->right!=NULL){
      if(node == node->parent->left){
        node->parent->left=node->right;
        node->right->parent=node->parent;
        free(node);
      }else if(node==node->parent->right){
        node->parent->right=node->right;
        node->right->parent=node->parent;
        free(node);
      }
    }
    else if((node->left!=NULL&&node->right==NULL)){
      if(node==node->parent->left){
        node->parent->left=node->left;
        node->left->parent=node->parent;
        free(node);
      }
      else if(node==node->parent->right){
        node->parent->right=node->left;
        node->left->parent=node->parent;
        free(node);
      }
      
    }
  }
  
}
  else{
    TreeNode*min = minium(node->right);
    node->pair->key=min->pair->key;
    node->pair->value=min _>pair->value
      removeNode(tree, min)
  }
}
void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
  tree->current=tree->root;
  while(tree->current!=NULL){
    if(is_equal(tree, key,tree->current->pair->key)){
      return tree->current->pair;
    }
    else if(tree->lower_than(key,tree->current->pair->key)==0){
      tree->current=tree->current->right;
      
    }else{
      tree->current=tree->current->left;
    }
  }
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
