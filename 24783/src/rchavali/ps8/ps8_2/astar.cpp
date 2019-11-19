#include "astar.h"
#include <math.h>
#include <iostream>
#include <stdio.h>

double heuristic_cost_estimate(const YsShellExt &shl, YsShellExt::VertexHandle vt1, YsShellExt::VertexHandle vt2)
{
	return shl.GetEdgeLength(vt1, vt2);
}

std::vector <YsShellExt::VertexHandle> A_Star(const YsShellExt &shl,YsShellExt::VertexHandle startVtHd,YsShellExt::VertexHandle goalVtHd)
{
	std::unordered_set<YSHASHKEY> closedSet;
	YsAVLTree<double, YsShellExt::VertexHandle> fScore_to_VtHd_tree;
	auto startVtHd_HK = shl.GetSearchKey(startVtHd);
	std::unordered_set<YSHASHKEY> openSet = {startVtHd_HK};
	std::unordered_map<YSHASHKEY, YsShellExt::VertexHandle> cameFrom;
	std::unordered_map<YSHASHKEY, YsAVLTree<double, YsShellExt::VertexHandle>::NodeHandle> VtHd_to_NdHd_map;
	std::unordered_map<YSHASHKEY, double> g_score;
	
	for(auto fromVtHd : shl.AllVertex()){
		auto NdHd = fScore_to_VtHd_tree.Insert(INFINITY, fromVtHd);
		auto fromVtHd_HK = shl.GetSearchKey(fromVtHd);
		VtHd_to_NdHd_map[fromVtHd_HK] = NdHd;
		g_score[fromVtHd_HK] = INFINITY;
	}
	
	auto startNdHd = VtHd_to_NdHd_map[startVtHd_HK];
	fScore_to_VtHd_tree.Delete(startNdHd);
	auto startVtHd_fScore = heuristic_cost_estimate(shl, startVtHd, goalVtHd);
	auto NdHd = fScore_to_VtHd_tree.Insert(startVtHd_fScore, startVtHd);
	VtHd_to_NdHd_map[startVtHd_HK] = NdHd;
	g_score[startVtHd_HK] = 0.0;


	while (!openSet.empty())
	{
		auto currentNdHd = fScore_to_VtHd_tree.First();
		auto currentVtHd = fScore_to_VtHd_tree.GetValue(currentNdHd);
		if (currentVtHd == goalVtHd){
			return A_Star_ReconstructPath(shl, cameFrom, currentVtHd);
		}
		openSet.erase(shl.GetSearchKey(currentVtHd));
		closedSet.insert(shl.GetSearchKey(currentVtHd));

		auto allNeighborVtHd = shl.GetConnectedVertex(currentVtHd);
		for(auto neighborVtHd : allNeighborVtHd)
		{
			auto search = closedSet.find(shl.GetSearchKey(neighborVtHd));
			if (search != closedSet.end())
			{
				continue;
			}
			search = openSet.find(shl.GetSearchKey(neighborVtHd));
			if (search == openSet.end())
			{

				openSet.insert(shl.GetSearchKey(neighborVtHd)); 
			}
			auto tentative_gScore = g_score[shl.GetSearchKey(currentVtHd)]+shl.GetEdgeLength(currentVtHd, neighborVtHd);
			if (tentative_gScore >= g_score[shl.GetSearchKey(neighborVtHd)])
			{
				continue;
			}
			cameFrom[shl.GetSearchKey(neighborVtHd)] = currentVtHd;
			g_score[shl.GetSearchKey(neighborVtHd)] = tentative_gScore;
			auto neighbour_fScore = g_score[shl.GetSearchKey(neighborVtHd)] + heuristic_cost_estimate(shl, neighborVtHd, goalVtHd);
			auto neighborNdHd = VtHd_to_NdHd_map[shl.GetSearchKey(neighborVtHd)];
			fScore_to_VtHd_tree.Delete(neighborNdHd);
			neighborNdHd = fScore_to_VtHd_tree.Insert(neighbour_fScore, neighborVtHd);
			VtHd_to_NdHd_map[shl.GetSearchKey(neighborVtHd)] = neighborNdHd;

		}
		fScore_to_VtHd_tree.Delete(currentNdHd);

	}
	
	return std::vector <YsShellExt::VertexHandle>(); 
}

std::vector <YsShellExt::VertexHandle> A_Star_ReconstructPath(
    const YsShellExt &shl,const std::unordered_map <YSHASHKEY,YsShellExt::VertexHandle> &cameFrom,YsShellExt::VertexHandle currentVtHd)
{

	std::vector <YsShellExt::VertexHandle> path;
	path.push_back(currentVtHd);
	for(;;)
	{
		auto current_HK = shl.GetSearchKey(currentVtHd);
		auto count = cameFrom.count(current_HK);
		if(count==0)
		{
			break;
		}
		auto prevVtHd=cameFrom.at(current_HK);
		path.push_back(prevVtHd);
		currentVtHd = prevVtHd;
	}
	return path;
}