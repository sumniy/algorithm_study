function solution(board, moves) {
    var answer = 0;
    let stack = [];

    for(let i = 0;i<moves.length;i++)
    {
        let flag = false;
        let idx;

        for(let j=0;j<board.length;j++)
        {
            if(board[j][moves[i]-1] !== 0)
            {
                idx = j;
                flag = true;
                break;
            } 
        }

        if(flag)
        {
            if(stack.length !== 0 && stack[stack.length-1] === board[idx][moves[i]-1])
            {
                stack.pop();
                answer += 2;
            }
            else
            {
                stack.push(board[idx][moves[i]-1]);
            }
            board[idx][moves[i]-1] = 0;
        }
    }
    return answer;
}