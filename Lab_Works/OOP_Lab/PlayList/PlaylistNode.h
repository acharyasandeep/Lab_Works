#ifndef PLAYLIST_NODE_H
#define PLAYLIST_NODE_H
#include <string>
using namespace std;

class PlaylistNode
{
	private:
		string uniqueID;
		string songName;
		string artistName;
		int songLength;
		PlaylistNode *nextNodePtr;
	
	public:
		PlaylistNode();
		PlaylistNode(string id,string name,string artist,int length);
		void InsertAfter(PlaylistNode *current);
		void SetNext(PlaylistNode *current);
		string GetID();
		string GetSongName();
		string GetArtistName();
		int GetSongLength();
		PlaylistNode* GetNext();
		void PrintPlaylistNode();

};

#endif

