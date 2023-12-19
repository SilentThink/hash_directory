#include "hush.h"

//先将表头初始化，表头不存数据，方便后面的删除操作
Hush::Hush() {
  for(int i = 0; i < mod; i++) head[i] = new Linknode<pair<string, string> >(make_pair("null", "null"));
}

//哈希函数，将字符串当成一个P进制数，这里要主义+mod再进行%mod防止hash值为负数
int Hush::hashCode(string key) {
    int hash = 0;
    for(int i = 0; i < (int)key.size(); i++)
        //这段代码实现了一个简单的哈希函数，将字符串 key 转化为哈希值
        hash = ((hash * p % mod + (int)key[i]) % mod + mod) % mod;
    //qDebug() << QString::number(hash);
    return hash;
}

//查找键key是否在哈希表内
bool Hush::findKey(string key) {
    int val = hashCode(key);
    Linknode<pair<string, string> > *cur = head[val]->next;
    while(cur) {
        if(cur->pair.first == key) return true;
        cur = cur->next;
    }
    return false;
}

//根据hush查找key相应的value值
string Hush::find(string key) {
    int val = hashCode(key);
    Linknode<pair<string, string> > *cur = head[val]->next;
    while(cur) {
        if(cur->pair.first == key) return cur->pair.second;
        cur = cur->next;
    }
    return "未找到该单词";
}

//插入函数，向value相同的进行插入操作，我采用的是头插法，也就是向表头插入数据
void Hush::insert(string key, string value) {
    int val = hashCode(key);
    //如果当前插入的键已经被占用了则取消插入直接返回
    if(findKey(key)) return ;
    //否则进行键值对插入
    Linknode<pair<string, string> > *p = new Linknode<pair<string, string> >(make_pair(key, value));
    p->next = head[val]->next;
    head[val]->next = p;
}

//删除关键字的操作，具体操作就是链表的删除操作
void Hush::deleteKey(string key) {
    int val = hashCode(key);
    Linknode<pair<string, string> > *cur = head[val]->next, *pre = head[val];
    //这里如果要是找不到的话，就直接中止该操作
    if(!findKey(key)) return ;
    while(cur) {
        if(cur->pair.first == key) {
            pre->next = cur->next;
            delete cur;
            cur = nullptr;
            break ;
        }
        pre = cur;
        cur = cur->next;
    }
}

//析构函数，对内存进行释放
Hush::~Hush() {
    for(int i = 0; i < mod; i++) {
        Linknode<pair<string, string> > *cur = head[i];
        while(cur) {
            Linknode<pair<string, string> > *temp = cur;
            cur = cur->next;
            delete temp;
            temp = nullptr;
        }
    }
}


