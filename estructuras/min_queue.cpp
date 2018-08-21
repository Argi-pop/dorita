#define op(x,y) min(x,y)
#define type int

struct min_queue{
    // Queue that uses an arbitrary associative binary operation op(x,y)
    // Answers in O(1) the result of applying this operation to every element in the queue
    stack< pair<type, type> > s1, s2;
    int size(){
        return s1.size() + s2.size();
    }
    type get(){
        if(s1.empty() or s2.empty())
            return s1.empty() ? s2.top().second : s1.top().second;
        return op(s1.top().second, s2.top().second);
    }
    void push(type elem){
        type m = s1.empty() ? elem : op(elem, s1.top().second);
        s1.push( make_pair(elem, m) );
    }
    type pop(){
        if(s2.empty())
        while(!s1.empty()){
            type elem = s1.top().first;
            s1.pop();
            type m = s2.empty() ? elem : op(elem, s2.top().second);
            s2.push( make_pair(elem, m) );
        }
        s2.pop();
        return s2.top().first;
    }
};
