#include<iostream>
#include<vector>
using namespace std;
class Node{//�������ڵ�
private:
	string value;//����ֵ
	string to_value;//���������ֵ
public:
	vector<Node *> childs;//���еĺ���
	Node(){
		value = "";
		to_value = "";
	}
	void setChild(Node *child){
	    childs.push_back(child);
	}
	vector<Node*> getChild(){
	    return childs;
	}
	void setValue(string v){
	    value = v;
	}
	void setTo_Value(string to){
	    to_value =to;
	}
	string getValue(){
	    return value;
	}
	string getTo_value(){
	    return to_value;
	}
};
