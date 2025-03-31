#include <iostream>
#include <iomanip>

// classe template per numeri complessi
template <typename T>
class complex_number
{
	private:
	 T reale;
	 T immag;
	public :
	explicit complex_number(T a): reale(a), immag(0.0)
	{}
	// costruttore default
	 complex_number()
	    : reale(0), immag(0) 
		{}
	// costruttore user-defined
	 complex_number(T r, T i): reale(r), immag(i) 
	    {}
	// metodo per ottenere parte reale e parte immaginaria
	T get_reale() const   
	{
		return reale;
	}
	T get_immag() const
	{
		return immag;
	}
	// coniugato
	complex_number coniugato() const
	{
		return complex_number(reale, -immag);
	}
	
	// overload +=
	complex_number operator+= (const complex_number& other)
	{
		T a=reale;
		T b=immag;
		T c=other.reale;
		T d=other.immag;
		reale=a+c;
		immag=b+d;
		return *this;
	}
	// overload di + tra complessi
	complex_number operator+( const complex_number& other)
	{
		return complex_number(reale+other.reale, immag+other.immag);
	}
	
	// overload di + con complesso e altra classe
    complex_number operator+( const T& n) const
	{
		return complex_number(reale+n, immag);
	}
		
	// overload di *=
	complex_number operator*=( const complex_number& other) 
	{
		T e=reale;
		T f=immag;
		T g=other.reale;
		T h=other.immag;
		reale=e*f-g*h;
		immag= e*h+f*g;
		return *this;
	}
	
	// overload di * tra complessi
	complex_number operator*(const complex_number& other) const
	{
		T new_r= reale*other.reale-immag*other.immag;
		T new_i=reale*other.immag+immag*other.reale;
		return complex_number(new_r, new_i);
	}
	
	// overload di * tra complesso e altra classe
	complex_number operator*(const T& n) const
	{
		return complex_number(reale*n, immag*n);
	}
};

// overload operatore + -->altro+complesso
template <typename T>
complex_number<T> operator +(const T n, const complex_number<T>& z)
{
	return complex_number<T>(z.get_reale() +n, z.get_immag());
}

// overload operatore * -->altro*complesso
template <typename T>
complex_number<T> operator*(const T n, const complex_number<T>& z)
{
	return complex_number<T>(z.get_reale()*n, z.get_immag()*n);
}

// overload << 
template <typename T>
std::ostream & operator<<(std::ostream& out, const complex_number<T>& z)
{
	out<<z.get_reale();
	if (z.get_immag() >=0)
	{
		out << "+" <<z.get_immag()<<"i";
	}
	else
	{
		out<<" "<<z.get_immag()<<"i";
	}
	return out;
}
	
	
int main()
{
	complex_number<double> z1(3.3,4.4);
	complex_number<double> z2(-3.4,0.5);
	double n=9.0;
	
	std::cout<<std::fixed<<std::setprecision(1);
	std::cout<<"z1= "<<z1<<std::endl;
	std::cout<<"z2= "<<z2<<std::endl;
	std::cout<<"parte reale di z1 "<<z1.get_reale()<<std::endl;
	std::cout<<"parte immaginaria di z1 "<<z1.get_immag()<<std::endl;
	std::cout<<"parte reale di z2 "<<z2.get_reale()<<std::endl;
	std::cout<<"parte immaginaria di z2 "<<z2.get_immag()<<std::endl;
	std::cout<<"coniugato di z1: "<<z1.coniugato()<<std::endl;
	std::cout<<"coniugato di z2: "<<z2.coniugato()<<std::endl;
	
	// verifico degli overload delle operazioni
	// somma tra complessi
	complex_number<double> sumCC= z1+z2;
	std::cout<<" somma tra due numeri complessi z1+z2= "<<sumCC<<std::endl;
	
	// somma tra complesso e altro
	complex_number<double> sumCN=z1+n;
	std::cout<<" somma tra complesso e altro numero z1+n= "<<sumCN<<std::endl;
	
	// somma tra altro e complesso
	complex_number<double> sumNC=n+z2;
	std::cout<<" somma tra altro numero e complesso n+z2= "<<sumNC<<std::endl;
	
	// prodotto tra complessi
	complex_number<double> prodCC=z1*z2;
	std::cout<<" prodotto tra due complessi z1*z2= "<<prodCC<<std::endl;
	
	// prodotto tra complesso e altro numero
	complex_number<double> prodCN=z1*n;
	std::cout<<" prodotto tra complesso e altro numero z1*n= "<<prodCN<<std::endl;
	
	// prodotto tra altro numero e complesso
	complex_number<double> prodNC=n*z2;
	std::cout<<" prodotto tra altro numero e complesso n*z2= "<<prodNC<<std::endl;
	
	// operatore +=
	complex_number<double> SC=z1+=z2;
	std::cout<<" += : "<<SC<<std::endl;
	
	// operatore *=
	complex_number<double> PC=z1*=z2;
	std::cout<<" *= : "<<PC<<std::endl;
	
	return 0;
}