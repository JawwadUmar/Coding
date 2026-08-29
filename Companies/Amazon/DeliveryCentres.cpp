/*Given a binary grid, where the distance between cells is Chebyshev distance,
add at most one 1 such that the maximum distance of any 0 cell from its nearest 1 is minimized.
Return that minimum maximum distance.*/

// CHEBYSEV DISTANCE -> MIN(ABS(X1-X2), ABS(Y1-Y2))

// Quick test-case table
// #	Grid	                            Expected
// 1	[[0]]	                                0
// 2	[[1]]	                                0
// 3	[[1,0],[0,0]]	                        1
// 4	[[0,0,0,0],[0,0,0,0],[0,0,0,0]]	        2
// 5	[[0,0,1],[0,0,0],[1,0,0]]	            1
// 6	[[1,0,0,0]]	                            1
// 7	[[1,1],[1,1]]	                        0
// 8	[[0,0,0,1],[0,0,0,1]]	                1


