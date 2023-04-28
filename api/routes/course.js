import express from 'express'
import { tokenVerification } from './auth';

import User from '../models/user';
import Chat from '../models/Chat';
import Course from '../models/Course';
import Content from '../models/content';
import Message from '../models/message';

const courseRoute = express.Router();
courseRoute.post('/addCourse',tokenVerification, async(req,res)=>{
    const {details, name} = req.body;
    try{
        const course = new Course({
            instructor:req.user,
            name,
            details,
        });
        await course.save();
        return res.status(200).json({msg:'Course Added', body:course});
    }
    catch(err){
        return res.status(500).json({msg:'Server Error'});
    }



} );



courseRoute.post('/getSAll', tokenVerification, async (req,res)=>{
    try{
        const courses = await Course.find();
        return res.status(200).json({body:courses});
    }
    catch(err){
        return res.status(500);
    }
})
courseRoute.post('/getAll', tokenVerification, async (req,res)=>{
    try{
        const courses = await Course.find({instructor : req.user}).populate('students');
        return res.status(200).json({body:courses});
    }
    catch(err){
        return res.status(500);
    }
})


courseRoute.post('/getCourse', tokenVerification, async (req,res)=>{
    const {id} = req.body;
    try{
        const course = await Course.findById(id)
        .populate('instructor')
        .populate('content').exec();
        return res.status(200).json({body:course});
    }catch(err){
        return res.status(500);
    }
})


export default courseRoute;

//user 1 '6447612730622fdacbef85ea'
//2 '6447618c30622fdacbef85f1'