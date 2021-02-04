#include <iostream>
#include "PlaylistNode.h"

void AddSong(PlaylistNode* &playlist)
{
	cout<<"ADD SONG"<<endl;
	cout<<"Enter song\'s unique ID:"<<endl;
	string id;
	cin.ignore();
	getline(cin,id);
	cout<<"Enter song\'s name:"<<endl;
	string name;
	getline(cin,name);
	cout<<"Enter artist\'s name:"<<endl;
	string artist;
	getline(cin,artist);
	cout<<"Enter song\'s length (in seconds):";
	int length;
	cin>>length;
   cout<<endl<<endl;
	PlaylistNode *temp = new PlaylistNode(id,name,artist,length);
	if(playlist==nullptr)
	{
		playlist=temp;
		return;
	}

	PlaylistNode *curr=playlist;
	while(curr->GetNext()!=nullptr)
	{
		curr=curr->GetNext();
	}
	curr->InsertAfter(temp);
}
void RemoveSong(PlaylistNode* &playlist)
{
	cout<<"REMOVE SONG"<<endl;
	string id;
	cout<<"Enter song's unique ID:"<<endl;
	cin>>id;
	PlaylistNode* temp=playlist;
	
	while(temp!=nullptr) //finding the position of song;
	{

		if(temp==nullptr)
		{
			//empty playlist
			cout<<"Empty playlist"<<endl;
			return;
		}

		if(temp->GetNext()->GetID()==id)
		{
			if(temp->GetNext()==nullptr) //only one song in playlist
			{
				cout<<"\""<<temp->GetSongName()<<"\" removed."<<endl<<endl;

				PlaylistNode* temp1 = temp;
				temp=temp->GetNext();
				delete temp1;
				return;
			}

		
			cout<<"\""<<temp->GetNext()->GetSongName()<<"\" removed."<<endl<<endl;
			PlaylistNode* next = temp->GetNext()->GetNext();//store next node location
			PlaylistNode* curr = temp->GetNext();
			temp->SetNext(next); 
			delete curr;
			break;
		}
		temp=temp->GetNext();
	}
}


	




void TotalTimeOfPlaylist(PlaylistNode* &playlist)
{
	cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
	int total=0;
	PlaylistNode* temp=playlist;
	if(temp==nullptr)
	{
		cout<<"Playlist is empty"<<endl<<endl;
		return;
	}

	while(temp!=nullptr)
	{
		total+=temp->GetSongLength();
		temp=temp->GetNext();
	}
	cout<<"Total time: "<<total<<" seconds"<<endl<<endl;



}

void OutputPlaylist(PlaylistNode* &playlist,string title)
{
	cout<<title<<" - OUTPUT FULL PLAYLIST"<<endl;
	PlaylistNode* temp=playlist;
	if(temp==nullptr)
	   cout<<"Playlist is empty"<<endl<<endl;
	int i=0;
	while(temp!=nullptr)
	{
	   cout<<i+1<<"."<<endl;
	   temp->PrintPlaylistNode();
	   temp=temp->GetNext();
	   i++;
	}


}
void OutputByArtist(PlaylistNode* &playlist,string title)
{

	cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
	string artistName;
	cout<<"Enter artist\'s name:"<<endl;
	cin.ignore();
	getline(cin, artistName);
	cout<<endl;
	PlaylistNode* temp = playlist;
	int i=0;
	while(temp!=nullptr)
	{
		if(temp->GetArtistName()==artistName)
		{
			cout<<i+1<<"."<<endl;
			temp->PrintPlaylistNode();
			
		}
		i++;

		temp = temp->GetNext();
	}

}

void ChangePosition(PlaylistNode* &playlist)
{
	//to find the no of songs currently in playlist
	int n=0;
	PlaylistNode *temp = playlist;
	while(temp!=nullptr)
	{
		temp=temp->GetNext();
		n++;
	}
	cout<<n<<endl;

	//change position code;
	cout<<"CHANGE POSITION OF SONG"<<endl;
	int initPos;
	int finalpos;
	cout<<"Enter song\'s current position:"<<endl;
	cin>>initPos;
	cout<<"Enter new position for song:"<<endl;
	cin>>finalpos;
	if(initPos < 1 || initPos > n)
	{
		cout<<"Invalid position."<<endl;
		return;
	}
	//read the comments before nodes coz taking literal meaning can cause confusion

	PlaylistNode* curr = playlist; //this node points to the node that is  one position before prev;
	PlaylistNode* prev = nullptr; //this node points to the node that is to be moved
	PlaylistNode* next = playlist;//this node points to the node that is one position before the final position to be moved
	if(initPos == 1)//moving head node
	{
		prev = playlist;
		next = curr->GetNext();
	        playlist = next;//updating head node to the next which is now first node;

	}
	else
	{

		for(int i=0;i<initPos-2;i++)
		{
			curr = curr->GetNext();
		}

		prev = curr->GetNext(); //stored the current node to move

		curr->SetNext(prev->GetNext()); //skip prev node and move on
	}

        if(finalpos < 1)
		finalpos = 1; //self explanatory code

	if(finalpos > n)
		finalpos = n; //n is the no of nodes in list;

	cout<<"\""<<prev->GetSongName()<<"\" moved to position "<<finalpos<<endl<<endl;
	
	//moving to head node
	if(finalpos==1)
	{
	 	playlist = prev;//coz we moved prev to first position ie. head node
		prev->SetNext(next); //coz next is head node
		return; //finished our job so return;
	}
	for(int i=0;i<finalpos-2;i++)
		next = next->GetNext();


	prev->SetNext(next->GetNext()); //setnext of prevnode to the desired pos node 
	next->SetNext(prev); //set prev next to next coz next is in the position finpos-1(one less than desired position)

}


void PrintMenu(string title,PlaylistNode* &playlist)
{
	while(true)
	{
		cout<<title<<" PLAYLIST MENU"<<endl;
		cout<<"a - Add song"<<endl;
		cout<<"d - Remove song"<<endl;
		cout<<"c - Change position of song"<<endl;
		cout<<"s - Output songs by specific artist"<<endl;
		cout<<"t - Output total time of playlist (in seconds)"<<endl;
		cout<<"o - Output full playlist"<<endl;
		cout<<"q - Quit"<<endl<<endl;

		char option;
		cout<<"Choose an option:";
		cin>>option;
		cout<<endl;
		while(option!='a' && option!='d' && option!='c' && option!='s' && option!='t' && option!='o' && option!='q')
		{
			cout<<"Choose an option:";
			cin>>option;
		}
		if(option=='q')
			break;

		switch(option)
		{
			case 'o':
				OutputPlaylist(playlist,title);
				break;

			case 'a':
				AddSong(playlist);
				break;

			case 'd':
				RemoveSong(playlist);
				break;

			case 'c':
				ChangePosition(playlist);
				break;

			case 's':
				OutputByArtist(playlist,title);
				break;

			case 't':
				TotalTimeOfPlaylist(playlist);
				break;

			default:
				break;

		}
	}
 

}
int main()
{
	cout<<"Enter playlist's title:"<<endl;
	string title;
	getline(cin,title);
	cout<<endl;

	PlaylistNode* playlist = nullptr;

	PrintMenu(title,playlist);
}

