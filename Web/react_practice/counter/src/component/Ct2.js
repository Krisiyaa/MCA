import React,{useState} from "react";

function Ct2(){
    const [ct,set] = useState(0);

    function inc(){
        set(ct+1);
    }

    function dec(){
        set(ct-1);
    }

    return(
        <>
        <h1>Counter : {ct}</h1>
        <button onClick={inc}>INC</button>
        <button onClick={dec} disabled={ct===0}>DEC</button>
        </>
    );
}

export default Ct2;