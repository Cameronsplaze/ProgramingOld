% take.pro
% Cameron Showalter
%
% For CS F331 / CSCE A331 Spring 2017
% Used in Assignment 7, Exercise B

% take-> input a number and two lists of at least size(number)
% Returns weither the first N items in both lists are equal

take(_, [], []).
take(0, _, []).
% take input: a int and two lists of at least size of int
% take output: weither the first int items in lists are equal, bool
take(N, [I|J], [I|K]):- M is N-1, take(M,J,K).