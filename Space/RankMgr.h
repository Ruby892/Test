#pragma once
class RankMgr : public Singleton<RankMgr>
{
public:
	RankMgr();
	~RankMgr();

	int m_Score;
};

