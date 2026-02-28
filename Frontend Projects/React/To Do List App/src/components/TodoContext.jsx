import {createContext, useState} from 'react'

export const TodoContext = createContext();

export const TodoProvider= ({children})=>{
  const [tasks,setTasks]=useState([]);

  const addTask=(text)=>{
    const newTask={id:Date.now(),text,completed:false};
    setTasks((prev)=>[...prev,newTask]);
  }

  const removeTask = (id) => {
    setTasks(tasks.filter((task)=>{
      return task.id !== id
    }));
  }

  const toggleTask = (id) => {
    setTasks(tasks.map((task)=>
      task.id===id?{...task,completed:!task.completed}:task
    ))
  }

  return(
    <TodoContext.Provider value={{tasks,addTask,removeTask,toggleTask}}>
      {children}
    </TodoContext.Provider>
  )
}
