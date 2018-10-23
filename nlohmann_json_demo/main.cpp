#include <iostream>
#include <string>
#include <array>
#include "json.hpp"

using json=nlohmann::json;
using namespace std;

namespace ns{
class  words{
        public:
                float score;
                string word;
};
class fluency{
        public:
                float SentenceStressScore;
                float WordsStressScore;
                float pauseScore;
                float wordScore;
};
class gop{
	public:
		float SentenceStressScore;
        	float WordsStressScore;
        	float consonant_score;
        	float error_no;
        	float pauseScore;
        	float sentence_score;
		float vowel_score;
		float wav_time;
		float wordScore;
		vector<words> words_info;
};
void from_json(const json& j,words& w){
	w.score=j.at("score");
	w.word=j.at("word");
}

void from_json(const json& j,gop& g){
	g.SentenceStressScore=j.at("SentenceStressScore");
	g.WordsStressScore=j.at("WordsStressScore");
	g.consonant_score=j.at("consonant_score");
	g.error_no=j.at("error_no");
	g.pauseScore=j.at("pauseScore");
	g.sentence_score=j.at("sentence_score");
	g.vowel_score=j.at("vowel_score");
	g.wav_time=j.at("wav_time");
	g.wordScore=j.at("wordScore");
	const json& sj=j.at("words_info");
	g.words_info.resize(sj.size());
	std::copy(sj.begin(),sj.end(),g.words_info.begin());
}
    void from_json(const json& j, fluency& f) {
        j.at("SentenceStressScore").get_to(f.SentenceStressScore);
        j.at("WordsStressScore").get_to(f.WordsStressScore);
        j.at("pauseScore").get_to(f.pauseScore);
        j.at("wordScore").get_to(f.wordScore);
    }
}
int main(){
	string s="{\"SentenceStressScore\":-1.0,\"WordsStressScore\":-1.0,\"pauseScore\":-1.0,\"wordScore\":-1.0}";
	string s2="{\"SentenceStressScore\": 54,\"WordsStressScore\": 54,\"consonant_score\": 54,\"error_no\": 0,\"pauseScore\": 54,\"sentence_score\": 49,\"vowel_score\": 54,\"wav_time\": 14.08500003814697,\"wordScore\": 54,\"words_info\": [{\"score\": 50,\"word\": \"HOW\"}, {\"score\": 50,\"word\": \"ARE\"}, {\"score\": 50,\"word\": \"YOU\"}]}";

	auto j =json::parse(s);
	auto j2=json::parse(s2);
	ns::fluency f=j;
	ns::gop g=j2;
	cout<<f.WordsStressScore<<endl;
	cout<<g.wav_time<<endl;
}
