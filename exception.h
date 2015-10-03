/*
Brent Ramsten

cst211

assignment #1
*/





#ifndef  exception_H
#define  exception_H
template <class INPUT>
class Exception
{
public:
	Exception();
	Exception(char msg);
	Exception(const Exception &copy);
	~Exception();
	Exception &operator=(Exception &rhs);
private:
	char *m_msg;
};

template <class INPUT>
Exception<INPUT>::Exception()
{
}

template <class INPUT>
Exception<INPUT>::Exception(char msg)
{
	if (msg == 'a')
	{
		cout << "allocation error\n";
		exit(EXIT_FAILURE);
	}
	if (msg == 'b')
	{
		cout << "outisde bounds error";
		exit(EXIT_FAILURE);
	}

}



template <class INPUT>
Exception<INPUT>::~Exception()
{
}


#endif
