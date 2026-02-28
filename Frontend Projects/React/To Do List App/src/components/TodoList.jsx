import {useState,useEffect,useRef,useContext} from 'react'
import {TodoContext} from './TodoContext'
import '../App.css'

const TodoList=()=>{
  const [input,setInput]=useState("");
  const inputRef=useRef(null);
  const {addTask}=useContext(TodoContext);
  
  useEffect(()=>{
    inputRef.current.focus();
  },[])

  const handleSubmit=(e)=>{
    e.preventDefault();
    if (!input.trim()) return;
    addTask(input);
    setInput("");
  }

  return(
    <>
      <form onSubmit={handleSubmit}>
        <input 
          type="text" 
          ref={inputRef} 
          onChange={(e)=>setInput(e.target.value)}
          value={input} 
          placeholder="Add To Do..." 
          />

       <button type="submit">Add</button>
        
      </form>
    </>
  )
}

export default TodoList;