#include <QString>

template <class T>
struct treap{
T key;
T priority;
treap* left=NULL;
treap* right=NULL;

};

template <class T>
void deleteTreapEl(treap<T>*& treapEl, T key){
  if (treapEl->key == key){
      merge(treapEl,treapEl->left,treapEl->right);
    }
  else if (treapEl->key<key){
      deleteTreapEl(treapEl->right,key);
    }
  else deleteTreapEl(treapEl->left,key);

}

template <class T>
void merge(treap<T>*& treapEl,treap<T>* leftTreapEl,treap<T>* rightTreapEl){
  if (leftTreapEl == NULL){
      treapEl = rightTreapEl;
    }
  else if (rightTreapEl == NULL){
      treapEl = leftTreapEl;
    }
  else if (leftTreapEl->priority<rightTreapEl->priority){
      merge(rightTreapEl->left,leftTreapEl,rightTreapEl->left);
      treapEl = rightTreapEl;
    }
  else{
      merge(leftTreapEl->right,leftTreapEl->right,rightTreapEl);
      treapEl = leftTreapEl;
    }
}

template <class T>
void isExistInTreapXorY(treap<T>* treapEl,treap<T>* findEl,bool& res = false){
  if (treapEl->key==findEl->key||treapEl->priority==findEl->priority){
      res = true;
      return;
    }
  if (treapEl->left!=NULL) isExistInTreapXorY(treapEl->left,findEl,res);
  if (treapEl->right!=NULL) isExistInTreapXorY(treapEl->right,findEl,res);
}

template <class T>
bool isExistInTreap(treap<T>* treapEl,treap<T>* findEl){
  if (treapEl == NULL){
      return false;
    }
  else if(findEl->key < treapEl->key){
          isExistInTreap(treapEl->left,findEl);
    }
  else if(findEl->key > treapEl->key){
          isExistInTreap(treapEl->right,findEl);
    }
  else{
      if (findEl->priority == treapEl->priority)
        return true;
      else return false;
    }
}

template <class T>
void QPrintTreap(treap<T>* treapEl,int level = 0,bool isLeft = true,QString& result=""){
  for (int i=0;i<level;++i)
   result+="-";
  if (isLeft) result+=">";
   else result+="<";
  result+="(" + QString::number(treapEl->key) + "," + QString::number(treapEl->priority)+")";
  result += "\n";
  if (treapEl->left!=NULL) {QPrintTreap(treapEl->left,++level,true,result);
    --level;}
  if (treapEl->right!=NULL) {QPrintTreap(treapEl->right,++level,false,result);
    --level;}
}


template <class T>
void insertElInTreap(treap<T>*& treapEl,treap<T>* insertTreapEl){

  if (treapEl == NULL){
      treapEl = insertTreapEl;
    }
  else if (treapEl->priority<insertTreapEl->priority){
      split(treapEl,insertTreapEl->key,insertTreapEl->left,insertTreapEl->right);
      treapEl = insertTreapEl;
    }
  else {if (insertTreapEl->key>treapEl->key) insertElInTreap(treapEl->right,insertTreapEl);
  else insertElInTreap(treapEl->left,insertTreapEl);}
}

template <class T>
  void split(treap<T>* treapEl,T searchKey,treap<T>*& leftTreap,treap<T>*& rightTreap){
    if (treapEl == NULL){
        leftTreap = NULL;
        rightTreap = NULL;
      }
    else if(searchKey < treapEl->key){

            split(treapEl->left,searchKey,leftTreap,treapEl->left);
            rightTreap = treapEl;

      }
    else{

            split(treapEl->right,searchKey,treapEl->right,rightTreap);
            leftTreap = treapEl;

      }
  }

