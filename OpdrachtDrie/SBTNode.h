#ifndef SBTNODE_H
#define SBTNODE_H

template<class T>
class SBTNode {
public:

    T data;
    SBTNode *parent;
    SBTNode *left;
    SBTNode *right;

    SBTNode(){
        parent = NULL;
        left = NULL;
        right = NULL;
    };

    SBTNode(T &value){
        data = value;
    }

    ~SBTNode(){
        parent = NULL;
        left = NULL;
        right = NULL;
    };

    void operator=(const SBTNode<T> &value){
        data = value.data;
    };


};
#endif // SBTNODE_H
