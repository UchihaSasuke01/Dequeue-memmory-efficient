    #include <bits/stdc++.h>
    using namespace std;
     
    int c;//variable to count 
     
    struct node
    {
        int data;
        struct node* npx;
    };
    struct node *head; 
    struct node *tail;
     
    struct node* XOR (struct node *a, struct node *b)
    {
        return reinterpret_cast<struct node*>(
            reinterpret_cast<uintptr_t>(a)
            ^ reinterpret_cast<uintptr_t>(b));
    }
     
    void push_front(int data)
    {
        struct node *new_node  = (struct node *) malloc (sizeof (struct node) );
        new_node->data = data;
        new_node->npx=head; //Since head xor null=head
        if (head!= NULL)
        {
            (head)->npx = XOR(new_node,(head)->npx);
        }
        else
        {
        	tail=new_node;
        }
        head= new_node;
        c=c+1;
    }
     
    void pop_front()
    {
    	if(head==NULL)
    	{
    		cout<<"DELETION NOT POSSIBLE DEQUEUE IS EMPTY\n";
    	}
    	else
    	{
    	struct node *temp=head;
    	head=(head)->npx; //the adress part of first node contains the adress of next node since previous adress is null
    	if(head!=NULL)
    	(head)->npx=XOR(temp,(head)->npx);
    	else
    	tail=NULL;
    	cout<<temp->data<<" deleted\n";
    	c=c-1;
    	}
    }
     
     
    void pop_back()
    {
    	if(tail==NULL)
    	{
    	 cout<<"DELETION NOT POSSIBLE DEQUEUE IS EMPTY\n";
    	}
    	else
    	{
    	struct node *temp=tail;
    	tail=(tail)->npx; //the adress part of last node contains the adress of previous node since the next adress is null
    	if(tail!=NULL)
    	(tail)->npx=XOR(temp,(tail)->npx);
    	else
    	head=NULL;
    	c=c-1;
    	cout<<temp->data<<" deleted\n";
    	}
    }
     
     
    void push_back(int data)
    {
        struct node *new_node  = (struct node *) malloc (sizeof (struct node) );
        new_node->data = data;
        new_node->npx=tail;
        if (tail!= NULL)
        {
            (tail)->npx = XOR(new_node,(tail)->npx);
        }
        else
        {
        	head=new_node;
        }
        tail=new_node;
        c=c+1;
    }
     
    void printList ()
    {
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *next;
        if(head==NULL)
        {
            cout<<"Dequeue is empty";
        }
     
        while (curr != NULL)
        {
            cout<<curr->data<<" ";
            next = XOR (prev, curr->npx);
            prev = curr;
            curr = next;
        }
        cout<<"\n";
    }
     
     int size()
     {
     	return c;
     }
     
     bool IsEmpty()
     {
     	if(c==0)
     	return true;
     	return false;
     }
     
    struct node* get_front()
    {
    	if(head==NULL)
    	cout<<"Dequeue is empty so no front\n";
    	return head;
    }
     
    struct node* get_2front()
    {
    	if(head==NULL)
    	{
    	cout<<"Dequeue is empty so no 2nd front\n";
    	return head;
    	}
    	if(head->npx==NULL)
    	{
    	cout<<"Dequeue has only one element so no 2nd front\n";
    	}
    	return head->npx;
    }
     
    struct node* get_back()
    {
    	if(tail==NULL)
    	{
    		cout<<"Dequeue is empty so no back\n";
    	}
    	return tail;
    }
     
    struct node* get_2back()
    {
    	if(tail==NULL)
    	{
    		cout<<"Dequeue is empty so no 2nd back\n";
    		return tail;
    	}
     
    	if(tail->npx==NULL)
    	{
    	cout<<"Dequeue has only one element so no 2nd back\n";
    	}
    	return tail->npx;
    }
     
    int main ()
    {
        int a;
        cout<<"MENU\n1.PUSH FRONT\n2.PUSH BACK\n3.POP FRONT\n4.POP BACK\n5.SIZE\n6.IS_EMPTY\n7.GET FRONT\n8.GET 2ndFRONT\n9.GET BACK\n10.GET 2ndBACK\n11.PRINT ALL ELEMENTS PRESENT\n0.EXIT\n";
        cout<<"ENTER YOUR CHOICE:";
        cin>>a;
        while(true)
        {
        	if(a==1)
        	{
        		cout<<"Enter data to be inserted\n";
        		int data;
        		cin>>data;
        		push_front(data);
                cout<<data<<" Inserted\n";
        	}
        	else if(a==2)
        	{
        		cout<<"Enter data to be inserted\n";
        		int data;
        		cin>>data;
        		push_back(data);
                cout<<data<<" Inserted\n";
        	}
        	else if(a==3)
        	{
        		pop_front();
        	}
        	else if(a==4)
        	{
        		pop_back();
        	}
        	else if(a==5)
        	{
        		cout<<"The size of Dequeue:"<<size()<<"\n";
        	}
        	else if(a==6)
        	{
        		if(IsEmpty())
        		cout<<"Dequeue is empty\n";
        		else
        		cout<<"Dequeue is not empty\n";
        	}
        	else if(a==7)
        	{
             struct node *temp=get_front();
             if(temp!=NULL)
             cout<<"The data in the front:"<<temp->data<<"\n";
        	}
        	else if(a==8)
        	{
              struct node *temp=get_2front();
              if(temp!=NULL)
              cout<<"The data in the 2ndfront:"<<temp->data<<"\n";
        	}
        	else if(a==9)
        	{
              struct node *temp=get_back();
              if(temp!=NULL)
              cout<<"The data in the back:"<<temp->data<<"\n";
        	}
        	else if(a==10)
        	{
              struct node *temp=get_2back();
              if(temp!=NULL)
              cout<<"The data in the 2ndback:"<<temp->data<<"\n";
        	}
        	else if(a==11)
        	{
        	 printList();
        	}
        	else if(a==0)
        	{
        		cout<<"\nThank you";
        		exit(0);
        	}
        	else
        	{
        		cout<<"RECHECK AND TRY AGAIN\n";
        	}
        	cout<<"Enter your Choice:";
        	cin>>a;
        }
        return 0;
    }
