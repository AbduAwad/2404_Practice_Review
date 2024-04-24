#include <string>
#include <iostream>
#define MAX_ARR 200

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MOVIE CLASS DEFINITIONS                   */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Movie{	
	friend ostream& operator<<(ostream&, const Movie&);
	public:
		Movie(const string& title, const string& category);
		bool operator==(const string& t) const {return title == t;}	
        bool matches(const string& category) const {return this->category == category;}
	protected:
		virtual void print(ostream& ost) const = 0;
		string title;
		string category;
};

Movie::Movie(const string& title, const string& category): 
    title(title), category(category){}


// high definition
class HDMovie: public Movie{
	public:
		HDMovie (const string& title, const string& cat, const string& hd);
	protected:
		virtual void print(ostream& ost) const;
		string hdContent;
};

HDMovie::HDMovie(const string& title, const string& cat, const string& hd):
    Movie(title, cat), hdContent(hd){}

void HDMovie::print(ostream& ost) const{    
    ost << "HD Movie: " << title << " " << category << " " << hdContent << endl;
}


// standard definition
class SDMovie: public Movie{
	public:
		SDMovie (const string& title, const string& cat, const string& sd);
	protected:
		virtual void print(ostream& ost) const;
		string sdContent;
};

SDMovie::SDMovie(const string& title, const string& cat, const string& sd):
    Movie(title, cat), sdContent(sd){}

void SDMovie::print(ostream& ost) const{
    ost << "SD Movie: " << title << " " << category << " " << sdContent << endl;
}




/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MOVIELIST CLASS DEFINITIONS               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

class MovieList{
	
	class Node{
		public:
			Movie* data;
			Node* next;
	};
	
	public:
		MovieList();   
		~MovieList();
		// add to the front of the MovieList
		void addFront(Movie*);
		// add to the back of the MovieList
		void addBack(Movie*);
		
		// remove and return the Movie at the front
		Movie* removeFront();

        bool isEmpty() const {return head == nullptr;}

		
	private:
		Node* head;
		Node* tail;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MOVIELIST CLASS IMPLEMENTATIONS           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           ARRAY CLASS DEFINITION                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

template <class T>
class Array {
	public:
		Array();	
		~Array();
		// add T to the back of the array if there is room
		Array<T>& operator+=(const T&);
		// remove T if it exists
		Array<T>& operator-=(const T&);
		// return element at index, or call exit(1) on bad index
		T& operator[](int index);
		const T& operator[](int index) const;
		// inline functions
		int getSize() const { return numElements; }
		bool isFull() const { return numElements >= MAX_ARR;}
	
	private:
		int numElements;
		T* elements;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           ARRAY CLASS IMPLEMENTATION                */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           PROFILE AND FACTORY CLASS DEFINITIONS     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Profile{
    public:
        Profile(const string& name, const string& email);

        // Add all movies in the given list to the watchList.
        // The given list ml should be empty after this operation.
        void addToWatchList(MovieList& ml);
        void printWatchList();
        bool operator==(const string& n) const {return name == n;}
    private:
        string name;
        string email;
        MovieList watchList;
};

class Factory{
    public:
        Movie* makeMovie(const string& title, const string& cat, const string& content);
        Profile* makeProfile(const string& name, const string& email);
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*      PROFILE AND FACTORY CLASS IMPLEMENTATIONS      */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MOVIEFLIX CLASS DEFINITIONS               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */


class MovieFlix{
	public:
        MovieFlix();
		~MovieFlix();
		
		// make a new Movie and add it to the array 
		void addMovie(const string& title, const string& cat, 
			const string& content){
            movies += factory.makeMovie(title, cat, content);
        }

        bool addProfile(const string& name, const string& email){
            profiles += factory.makeProfile(name, email);
        }
		
        // Find all movies in the master list that match 
        // the given category and add them to the searchList.
		void searchByCategory(const string& category);

        // Find the profile with the given name and add all the movies
        // in the current searchList to their watchList. The searchList
        // should be empty after this operation.
        void addToWatchList(const string& profileName);

        void printWatchList(const string&) const;
        void printMovies() const;
	
	private:
				
		// master list of all movies
		Array<Movie*> movies;
        // master list of all profiles
        Array<Profile*> profiles;
        // current search results
        MovieList searchList;
        Factory factory;
};	

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MOVIEFLIX CLASS IMPLEMENTATIONS           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*           MAIN FUNCTION WITH TESTS                  */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main(){

    MovieFlix mf;

    string titles[] = {"D", "B","E", "A", "C"};
    string cats[] = {"X", "Y","X", "Y", "Z"};
    string content[] = {"X", "Y","X", "Y", "Z"};

    string names[] = {"Alice", "Bob", "Charlie", "Daphne", "Evan"};
    string emails[] = {"A", "B", "C", "D", "E"};

    cout<<"Adding movies"<<endl;
    for(int i = 0 ; i < 5; ++i){
        mf.addMovie(titles[i], cats[i], content[i]);
        mf.addProfile(names[i], emails[i]);
    }

    mf.printMovies();

    mf.printMovies();

    mf.searchByCategory("X");

    cout<<endl<<"Adding to watch list"<<endl<<endl;
    mf.addToWatchList("Alice");
    mf.printWatchList("Alice");

    cout<<endl<<"Adding Z to watch list"<<endl<<endl;
    mf.searchByCategory("Z");
    mf.addToWatchList("Bob");
    mf.printWatchList("Bob");


    return 0;

}