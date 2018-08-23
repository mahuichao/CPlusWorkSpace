#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct WavData{
	public:
		int16_t* data;
		long size;
		
		WavData(){
			data=NULL;
			size=0;
		}	
};


void loadWavFile(const char* fname,WavData *ret){
	FILE* fp=fopen(fname,"rb");
	if(fp){
		char id[5];
	        int32_t size;
		int16_t format_tag,channels,block_align,bits_per_sample;
		int32_t format_length,sample_rate,avg_bytes_sec,data_size;		
		
		fread(id,sizeof(char),4,fp);
		id[4]='\0';
		
		if(!strcmp(id,"RIFF")){
			fread(&size,sizeof(int16_t),2,fp);
			fread(id,sizeof(char),4,fp);
			id[4]='\0';

			if(!strcmp(id,"WAVE")){
				fread(id,sizeof(char),4,fp);
				fread(&format_length,sizeof(int16_t),2,fp);
				fread(&format_tag,sizeof(int16_t),1,fp);
				fread(&channels,sizeof(int16_t),1,fp);
				fread(&sample_rate,sizeof(int16_t),2,fp);
				fread(&avg_bytes_sec,sizeof(int16_t),2,fp);
				fread(&block_align,sizeof(int16_t),1,fp);
				fread(&bits_per_sample,sizeof(int16_t),2,fp);
				fread(id,sizeof(char),4,fp);
				fread(&data_size,sizeof(int16_t),2,fp);
				
				ret->size=data_size/sizeof(int16_t);
				// 动态分配了空间，记得要释放
				ret->data=(int16_t*)malloc(data_size);
				fread(ret->data,sizeof(int16_t),ret->size,fp);
			}
			else{
				cout<<"Error: RIFF File but not a wave file\n";
			}
		}
	else{
		cout<<"ERROR: not a RIFF file\n";
	}
	}
	fclose(fp);
}

void freeSource(WavData* data){
	free(data->data);
}

int main(){
	WavData song;
	ofstream out("city_16k.txt");
	const char* fname="city_16k.wav"; 
	loadWavFile(fname,&song);
	cout<<song.size<<endl;

	for(long i=0;i<song.size;i++){
		out<<song.data[i]<<',';
	}

	out.close();	
	freeSource(&song);
	return 0;
}


