function stack(){
    this.item = [];
}

function push(stack, str){
    let arr = stack.item;
    arr[arr.length] = str;
}

function pop(stack){
    let arr = stack.item;
    if (!arr.length) {
        return null;
    }
    else {
        let value = arr[arr.length - 1];
        arr.length = arr.length - 1;
        return value;
    }
}

function findPlace(MAXQUEEN){
    let i = 0;
    let j = 0;
    let stk = new stack();
    while (i < MAXQUEEN) { //每一行时第i列
        if (!attack(stk, i)) { //如果不冲突，号加入栈结构中。如果到达未尾，则成功
            push(stk, i);
            i = -1; //返回到下一行的第零列
            if (stk.item.length == MAXQUEEN) { //如果找到八个列值，则输出结果。
                showqueen(stk);
            }
        }
        i++;
        //行数，列数已经到达最后，则停止
        if(i>=MAXQUEEN && stk.item[0]>=MAXQUEEN-1){
            break;
        }
        while (i >= MAXQUEEN) {
            i = pop(stk) + 1;                  
        }
    }
}

/*
 * 在第K行第I列放置皇后是否冲突
 */
function attack(stk, i){
    let atk = false
    let k = stk.item.length; //i为第几行的数据
    for (var j = 0; !atk && j < k; j++) {
        atk = (stk.item[j] == i || Math.abs(k - j) == Math.abs(i - stk.item[j]));
    }
    return atk;
}

function showqueen(stk){
    console.info("********************")
    let queen = stk.item;
    for (let i = 0, cnt = queen.length; i < cnt; i++) {
        console.info("坐标为：(" + i + ", " +queen[i] + ")");
    }
}

let queen = [];
let MAXQUEEN = 10;
findPlace(MAXQUEEN);
